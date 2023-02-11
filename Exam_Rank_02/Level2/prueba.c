/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:16:05 by cmorales          #+#    #+#             */
/*   Updated: 2022/10/27 18:28:50 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_doubles(char *str, char c, int len)
{
	int i = 0;
	while(i < len)
	{
		if (str[i] == c)
			return(0);
		i++;
	}
	return(1);
}

int check_doubles1(char *str, char c)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return(0);
		i++;
	}
	return(1);
}

int main (int argc, char **argv)
{
	int i = 0;
	if(argc == 3)
	{
		while(argv[1][i])
		{
			if(check_doubles(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while(argv[2][i])
		{
			if(check_doubles1(argv[1], argv[2][i]))
			{
				if(check_doubles(argv[2], argv[2][i], i))
				{
					write(1, &argv[2][i], 1);
				}
			}
			i++;
		}		
	}
	write(1, "\n", 1);
	return (0);
}