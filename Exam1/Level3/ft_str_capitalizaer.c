/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalizaer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:40:09 by cristian          #+#    #+#             */
/*   Updated: 2022/06/25 13:56:44 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome una o varias cadenas y, para cada argumento
pone en mayúsculas el primer carácter de cada palabra (si es una letra, obviamente),
pone el resto en minúsculas, y muestra el resultado en la salida estándar,
seguido de un \n.
Una "palabra" se define como una parte de una cadena delimitada por espacios/tapas, o
por el inicio/fin de la cadena. Si una palabra sólo tiene una letra, debe ser
en mayúsculas. */

#include <unistd.h>

void	ft_str_capitalizaer(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		while (str[pos] && (str[pos] == ' ' || str[pos] == '\t'))
		{
			write (1, &str[pos], 1);
			pos++;
		}
		if (str[pos] && (str[pos] != ' ' || str[pos] != '\t'))
		{
			if (str[pos] >= 'a' && str[pos] <= 'z')
				str[pos] = str[pos] - 32;
			write (1, &str[pos], 1);
			pos++;

		}
		while (str[pos] && (str[pos] != ' ' || str[pos] != '\t'))
		{
			if (str[pos] >= 'A' && str[pos] <= 'Z')
				str[pos] = str[pos] + 32;
			write (1, &str[pos], 1);
			pos++;
		}
	}
	write (1, "\n", 1);
}

int main (int argc, char **argv)
{
	if (argc == 1)
		write (1, "\n", 1);
	else
	{
		int	pos;

		pos = 1;
		while (pos < argc)
		{
			ft_str_capitalizaer(argv[pos]);
			pos++;
		}
	}
	return (0);
}