/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:22:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/09/26 20:50:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int ft_print_err(const char *src)
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
		return(ft_print_err("error bad arguments\n"));
	else if(chdir(av[1]) == -1)
		return(ft_print_err("Can not change directory\n"));
	else
		return (0);
}

int main()
{
	ft_print_err("No sale\n");
}