/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:04 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/20 18:17:39 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome una cadena y muestre su última palabra seguida de una \n.
Una palabra es una sección de la cadena delimitada por espacios/tablas o por el inicio/fin de
la cadena.
Si el número de parámetros no es 1, o no hay palabras, muestra una nueva línea. */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc == 2)
	{
		while (argv[1][pos])
			pos++;
		pos--;
		while (argv[1][pos] != ' ' && argv[1][pos] != '\t' && pos >= 0)
			pos--;
		//pos++;
		while (argv[1][pos])
		{
			write (1, &argv[1][pos], 1);
			pos++;
		}
	}
	write (1, "\n", 1);
	return (0);
}