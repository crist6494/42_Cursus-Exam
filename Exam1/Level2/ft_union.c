/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:14 by cristian          #+#    #+#             */
/*   Updated: 2022/06/21 18:00:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome dos cadenas y muestre, sin dobles, los
caracteres que aparecen en cualquiera de las cadenas.
La visualización se hará en el orden en que aparecen los caracteres en la línea de comandos, y
irá seguido de un \n.
Si el número de argumentos no es 2, el programa muestra \n. */

#include <unistd.h>

int	check_doubles(char *str, char c, int position)
{
	int	pos;

	pos = 0;
	while (pos < position)
	{
		if (str[pos] == c)
			return (0);
		pos++;
	}
	return (1);
}

int	check_doubles1(char *str, char c)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == c)
			return (0);
		pos++;
	}
	return (1);
}

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc == 3)
	{
		while (argv[1][pos])
		{
			if (check_doubles(argv[1], argv[1][pos], pos))
				write (1, &argv[1][pos], 1);
			pos++;
		}
		pos = 0;
		while (argv[2][pos])
		{
			if (check_doubles1(argv[1], argv[2][pos]))
			{
				if (check_doubles(argv[2],argv[2][pos], pos))
					write (1, &argv[2][pos], 1);
			}
			pos++;
		}
	}
	write (1, "\n", 1);
	return (0);
}