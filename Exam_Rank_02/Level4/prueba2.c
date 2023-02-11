/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:28:21 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/22 13:35:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int i = 0;
	int start;
	int end;
	int space;

	if (argc == 2)
	{
		while (argv[1][i] != '\0')
			i++;
		while (i >= 0)
		{
			while (argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while (argv[1][i]&& argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			space = start;
			while (start <= end)
			{
				write(1, &argv[1][start], 1);
				start++;
			}
			if(start != 0)
				write (1, " ", 1);
		}
	}
	write (1, "\n", 1);
}