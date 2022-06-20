/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:00:48 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/20 17:21:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome dos cadenas y muestre, sin dobles, los
caracteres que aparecen en ambas cadenas, en el orden en que aparecen 
en la primera de la primera.
La visualización irá seguida de un \n.
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

int main (int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					if (check_doubles (argv[1], argv[1][i], i))
					{
						write (1, &argv[1][i], 1);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}