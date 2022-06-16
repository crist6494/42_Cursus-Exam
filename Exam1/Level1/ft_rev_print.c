/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:39 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/16 18:06:24 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome una cadena, y muestre la cadena al revés
seguida de una nueva línea.
Si el número de parámetros no es 1, el programa muestra una nueva línea. */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc == 2)
	{
		while (argv[1][pos])
			pos++;
		while (pos)
		{
			pos--;
			write (1, &argv[1][pos], 1);
		}
	}
	write(1,"\n", 1);
	return (0);
}