/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:11:33 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/22 18:16:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome una cadena, y muestre esta cadena con exactamente un
espacio entre las palabras, sin espacios ni tabulaciones ni al principio ni al final,
seguido de una \N palabra.
Una "palabra" se define como una parte de una cadena delimitada por espacios/tablas, o
por el inicio/final de la cadena.
Si el número de argumentos no es 1, o si no hay palabras que mostrar, el
programa muestra \n. */

#include <unistd.h>
#include <stdio.h>

int	main (int argc, char **argv)
{
	int	pos;
	int space;
	pos = 0;
	space = 0;
	if (argc == 2)
	{
		while (argv[1][pos] == ' ' || argv[1][pos] == '\t')
			pos++;
		while (argv[1][pos])
		{
			if (argv[1][pos] == ' ' || argv[1][pos] == '\t')
				space = 1;
			if (argv[1][pos] != ' ' && argv[1][pos] != '\t')
			{
				if (space == 1)
				{
					write(1, " ", 1);
					space = 0;
				}
				write (1, &argv[1][pos], 1);
			}
			pos++;
		}
	}
	write (1, "\n", 1);
	return (0);
}