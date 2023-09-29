#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/wait.h>

int p_err(const char *src)
{
	while(*src)
		write(2, src++, 1);
	return(1);
}

int cd(char **av, int i)
{
	if(i != 2)
		return(p_err("error: cd: bad arguments\n"));
	else if(chdir(av[1]) == -1)
		return(p_err("error: cd: cannot change directory to "), p_err(av[1]), p_err("\n"));
	return(0);
}

int exec(char **av, char **env, int i)
{
	int status;
	int fd[2];
	int has_pipe;

	if(av[i] && !strcmp(av[i], "|"))
		has_pipe = 1;
	else
		has_pipe = 0;
	
	if(has_pipe && pipe(fd) == -1)
		return(p_err("error: fatal\n"));
	
	int pid = fork();

	if(pid == -1)
		return(p_err("error: fatal\n"));
	if(!pid)
	{
		av[i] = 0;//Para que excevec sepa cuando termina los argumentos
		if(has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return(p_err("error: fatal\n"));
		execve(*av, av, env);
		return(p_err("error: cannot execute "), p_err(*av), p_err("\n"));
	}
	waitpid(pid, &status, 0);//Esperamos al hijo
	if(has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return(p_err("error: fatal\n"));
	if(WIFEXITED(status))//Si el codigo fue correcto devuelve el estado de salida del proceso hijo
		return(WEXITSTATUS(status));
	else
		return(1);
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	int status = 0;

	if(ac > 1)
	{
		while(av[i] && av[++i])//Sumamos aqui antes y comprobamos para no saltar a las env
		{
			av += i;
			i = 0;
			while(av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if(!strcmp(*av, "cd"))
				status = cd(av, i);
			else if(i)
				status = exec(av, env, i);
		}
	}
	return(status);
}