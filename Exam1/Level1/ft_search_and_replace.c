/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:36:03 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/16 19:54:47 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa llamado buscar_y_reemplazar que tome 3 argumentos, el primer 
argumentos es una cadena en la que sustituir una letra (2º argumento) por
otra (3er argumento).
Si el número de argumentos no es 3, sólo muestra una nueva línea.
Si el segundo argumento no está contenido en el primero (la cadena)
entonces el programa simplemente reescribe la cadena seguida de una nueva línea. */

#include "unistd.h"

int	main (int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc == 4)
	{
		while (argv[1][pos])
		{
			if (argv[1][pos] == argv[2][0])
				write (1, &argv[3][0], 1);
			else
				write (1, &argv[1][pos], 1);
			pos++;
		}
	}
	write (1, "\n", 1);
}