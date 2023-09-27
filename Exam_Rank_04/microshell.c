/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:22:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/09/27 21:06:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

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
	(void)i;
	char *buffer;
	//if(i != 2)
		//return(print_err("Error: bad arguments\n"));
	if(chdir(av[2]) == 0)
	{
		buffer = getcwd(NULL, 0);
		if (!buffer)
			return(print_err("Directory not found\n"));
		printf("Directorio actual: %s\n", buffer);
	}
	else
		return(print_err("Error: cd: cannot change directory to path_to_change: "), print_err(av[2]), print_err("\n"));
	return (0);
}

int exec(char **av, char **env, int i)
{
	(void)i;
	int fd[2];
	int status;
	int has_pipe = av[i] && (strcmp(av[1], "|") == 0);

	if(has_pipe && pipe(fd) == -1)
		return(print_err("error: fatal\n"));
	int pid = fork();

	if(pid == 0)
	{
		av[i] = 0;
		if(has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0] == -1) || close(fd[1]) == -1))
			return(print_err("error: fatal\n"));
		execve(*av, av, env);
		return print_err("error: cannot execute "), print_err(*av), print_err("\n"); 
	}
	waitpid(pid, &status, 0);
	if(has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0] == -1) || close(fd[1]) == -1))
		return(print_err("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env)
{
	int status;
	int i = 0;
	
	if(ac > 1)
	{
		while(av[i] && av[i++])
		{
			av += i;
			i = 0;
			while(av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if(strcmp(av[1], "cd") == 0)
				status = cd(av, i);
			else if(i != 0)
				status = exec(av, env, i);
		}
	}
	return (status);
}