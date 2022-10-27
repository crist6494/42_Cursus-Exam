/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstr_capitalizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:47:13 by cristian          #+#    #+#             */
/*   Updated: 2022/10/05 17:49:04 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*/Escribe un programa que tome una o más cadenas y, para cada argumento, ponga 
el último carácter que es una letra de cada palabra en mayúsculas y el resto
en minúsculas, y luego muestre el resultado seguido de una \n.
Una palabra es una sección de la cadena delimitada por espacios/tablas o el inicio/
fin de lacadena. Si una palabra tiene una sola letra, debe ir en mayúscula. */

#include <unistd.h>

void	ft_rstr_capitalizer(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		while (str[pos] && (str[pos] == ' ' || str[pos] == '\t'))
		{
			write(1, &str[pos], 1);
			pos++;
		}

		while (str[pos] && str[pos] != ' ' && str[pos] != '\t')
		{
			if (str[pos] >= 'a' && str[pos] <= 'z' && (str[pos + 1] == '\0' || str[pos + 1] == ' ' || str[pos + 1] == '\t'))
				str[pos] = str[pos] - 32;
			else if (str[pos] >= 'A' && str[pos] <= 'Z' && str[pos + 1] && str[pos + 1] != ' ' && str[pos + 1] != '\t')
				str[pos] = str[pos] + 32;
			write(1, &str[pos], 1);
			pos++;
		}
	}
	write(1, "\n", 1);
}
int	main (int argc, char **argv)
{
	if (argc == 1)
		write (1, "\n", 1);
	else 
	{
		int	pos;
		pos = 1;
		while (pos < argc)
		{
			ft_rstr_capitalizer(argv[pos]);
			pos++;
		}
	}
	return (0);
}