#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int print_err(const char *str)
{
	while(*str)
	{
		write(STDERR_FILENO, str++, 1);
	}
	return (1);
}

int cd(char **av, int i)
{
	if(i != 2)
		return (print_err("error: cd: bad arguments\n"));
	if(chdir(av[1]) == -1)
		return(print_err("error: cd: cannot change directory to path_to_change"), print_err(*av), print_err("\n"));
	return (0);
}

int exec(char **av, char **env, int i)
{
	int status;
	int fd[2];
	int has_pipe = av[i] && !strcmp(av[i], "|");

	if(has_pipe && pipe(fd) == -1)
		return (print_err("error:fatal\n"));
	int pid;

	pid = fork();
	if(pid == -1)
		return (print_err("error:fatal\n"));
	if(pid == 0)
	{
		av[i] = 0;
		if(has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1] == -1)))
			return print_err("error: fatal\n");
		execve(*av, av, env);
		return print_err("error: cannot execute "), print_err(*av), print_err("\n");
	}
	else
	{
		if(has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1] == -1)))
			return print_err("error: fatal\n");
		waitpid(pid, &status, 0);
	}
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	int status;

	if(ac > 1)
	{
		while(av[i] && av[i++])
		{
			av += i;
			i = 0;
			while(av[i] && (strcmp(av[i], "|") && strcmp(av[i], ";")))
				i++;
			if(!strcmp(*av, "cd"))
				status = cd(av, i);
			else if(i)
				status = exec(av, env, i);
		}
	}
	return (status);
}