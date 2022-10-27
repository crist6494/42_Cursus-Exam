/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:13:22 by cmorales          #+#    #+#             */
/*   Updated: 2022/10/06 20:29:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char **ft_split(char *str)
{
	int i = 0;
	int i2 = 0;
	int i3;
	char **esp;
	
	esp = (char**)malloc(sizeof(char) * 100);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] > ' ')
		{
			i3 = 0;
			esp[i2] = (char*)malloc(sizeof(char) * 100);
			while (str[i] > ' ')
			{
				esp[i2][i3] = str[i];
				i++;
				i3++;
			}
			esp[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	esp[i2] = 0;
	return (esp);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int main (int argc, char **argv)
{
	int i = 1;
	char **esp;

	if (argc > 1)
	{
		esp = ft_split(argv[1]);
		while (esp[i])
		{
			ft_putstr(esp[i]);
			write (1, " ", 1);
			i++;
		}
		ft_putstr(esp[0]);
	}
	return (0);
}