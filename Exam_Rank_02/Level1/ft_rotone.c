/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:14:59 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/16 19:32:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome una cadena y la muestre, sustituyendo cada una de sus
letras por la siguiente en orden alfabético.
La 'z' se convierte en 'a' y la 'Z' en 'A'. Las mayúsculas y minúsculas no se ven afectadas.
La salida irá seguida de un \n.
Si el número de argumentos no es 1, el programa muestra \n. */

#include <unistd.h>

int	main (int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc == 2)
	{
		while (argv[1][pos])
		{
			if (argv[1][pos]>= 'a' && argv[1][pos] < 'z')
				argv[1][pos] = argv[1][pos] + 1;
			else if (argv[1][pos]>= 'A' && argv[1][pos] < 'Z')
				argv[1][pos] = argv[1][pos] + 1;
			else if (argv[1][pos] == 'z')
				argv[1][pos] = argv[1][pos] = 'a';
			else if (argv[1][pos] == 'Z')
				argv[1][pos] = argv[1][pos] = 'A';
			write (1, &argv[1][pos], 1);
			pos++;
		}
	}
	write (1, "\n", 1);
	return (0);
}