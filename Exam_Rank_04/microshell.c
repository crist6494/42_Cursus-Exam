/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:22:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/09/28 11:54:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"
#include "stdlib.h"

int print_err(const char *src)
{
	while(*src)
	{
		write(STDERR_FILENO, src, 1);
		src++;
	}
	return (1);
}

int cd(char **av, int i)
{
	if(i != 2)
		return(print_err("Error: bad arguments\n"));
	if(chdir(av[1]) == 0)
	{
		printf("Av: %s\n", av[0]);
		char *buffer;
		buffer = getcwd(NULL, 0);
		if (!buffer)
			return(print_err("Directory not found\n"));
		printf("Directorio actual: %s\n", buffer);
		free(buffer);
	}
	else
		return(print_err("Error: cd: cannot change directory to path_to_change: "), print_err(av[2]), print_err("\n"));
	return (0);
}

/* int cd(char **argv, int i) 
{
    if (i != 2)
        return print_err("error: cd: bad arguments\n"); // Return an error if the argument count is not 2
    else if (chdir(argv[1]) == -1)
        return print_err("error: cd: cannot change directory to "), print_err(argv[1]), print_err("\n"); // Return an error if directory change fails
	else
	{
		char *buffer;
		buffer = getcwd(NULL, 0);
		if (!buffer)
			return(print_err("Directory not found\n"));
		printf("Directorio actual: %s\n", buffer);
		free(buffer);
	}
    return 0; // Return 0 on success
}  */

int exec(char **av, char **env, int i)
{
    int fd[2];
    int status;
    int has_pipe = av[i] && (strcmp(av[1], "|") == 0);

    if (has_pipe && pipe(fd) == -1)
        return print_err("error: fatal\n");

    int pid = fork();

    if (pid == 0)
    {
        av[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return print_err("error: fatal\n");
        execve(*av, av, env);
        return print_err("error: cannot execute "), print_err(*av), print_err("\n");
    }
    else
    {
        if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return print_err("error: fatal\n");
        waitpid(pid, &status, 0);
    }
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **env)
{
	int status;
	int i = 0;
	
	if(ac > 1)
	{
		while(av[i])
		{
			i++;
			av += i;
			i = 0;
			while(av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if(strcmp(*av, "cd") == 0)
				status = cd(av, i);
			else if(i != 0)
				status = exec(av, env, i);
		}
	}
	return (status);
}