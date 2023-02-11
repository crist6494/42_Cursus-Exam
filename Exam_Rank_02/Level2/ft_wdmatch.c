/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:18:22 by cmorales          #+#    #+#             */
/*   Updated: 2022/09/28 18:39:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome dos cadenas y compruebe si es posible
escribir la primera cadena con caracteres de la segunda cadena, respetando
el orden en que aparecen estos caracteres en la segunda cadena.
Si es posible, el programa muestra la cadena, seguida de un \n, en caso contrario
simplemente muestra un \n.
Si el número de argumentos no es 2, el programa muestra un \n. */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		write (1, &str[pos], 1);
		pos++;
	}
}

int	ft_strlen (char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
		pos++;
	return (pos);
}

#include <unistd.h>

int	main (int argc, char **argv)
{
	int	pos;
	int	pos2;
	int wdlen;

	pos = 0;
	pos2 = 0;
	wdlen = 0;
	if (argc == 3)
	{
		while (argv[1][pos])
		{
			while (argv[2][pos2])
			{
				if (argv[1][pos] == argv[2][pos2])
				{
					wdlen++;
					break;
				}
				pos2++;
			}
			pos++;
		}
		if (wdlen == ft_strlen(argv[1]))
			ft_putstr(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}