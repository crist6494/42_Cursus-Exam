/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:13:22 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/22 13:25:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int i = 0;
	int start;
	int end;
	int space = 0;

	if (argc > 1)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		start = i;
		while(argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			i++;
		end = i;
		while(argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while(argv[1][i] != '\0')
		{
			space = 1;
			write(1, &argv[1][i], 1);
			i++;	
		}
		if(space == 1)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
}