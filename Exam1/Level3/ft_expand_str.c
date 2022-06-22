/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:34:53 by cristian          #+#    #+#             */
/*   Updated: 2022/06/22 18:47:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Escriba un programa que tome una cadena y la muestre con exactamente tres espacios
entre cada palabra, sin espacios ni tabulaciones ni al principio ni al final,
seguido de una nueva línea.
Una palabra es una sección de la cadena delimitada por espacios/tablas, o por el
inicio/fin de la cadena.
Si el número de parámetros no es 1, o si no hay palabras, simplemente muestra
una nueva línea. */

#include <unistd.h>

int	main (int argc, char **argv)
{
	int	pos;
	int	space;

	space = 0;
	pos = 0;
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
					write (1, "   ", 3);
					space = 0;
				}
				write (1, &argv[1][pos], 1);				
			}	
			pos++;
		}
	}	
	return (0);
}