/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:14:24 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/15 20:06:47 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome una cadena y muestre su primera palabra, seguida de una
línea nueva.
Una palabra es una sección de la cadena delimitada por espacios/tablas o por el inicio/fin de
la cadena.
Si el número de parámetros no es 1, o si no hay palabras, simplemente muestra
una nueva línea. */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	pos;
	pos = 0;
	
	if (argc == 2)
	{
		while(argv[1][pos] != ' ' && argv[1][pos] != '\0' && argv[1][pos] != '\t')
		{
			write(1, &argv[1][pos], 1);
			pos++;
		}
	}
	write(1, "\n", 1);
	return (0);
}