/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camel_to_snake.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:38:24 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/19 17:24:28 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome una cadena en formato lowerCamelCase
y la convierta en una cadena en formato snake_case.
Una cadena lowerCamelCase es una cadena en la que cada palabra comienza con una letra mayúscula
excepto la primera.
Una cadena snake_case es una cadena en la que cada palabra está en minúsculas, separada por
un guión bajo "_". */

#include <unistd.h>

void	camel_to_snake(char *str)
{
	int	pos;
	pos = 0;
	
	while(str[pos])
	{
		if (str[pos] >= 'A' && str[pos] <= 'Z')
		{	
			write(1, "_", 1);
			str[pos] = str[pos] + 32;
		}
		write(1, &str[pos], 1);
		pos++;
	}
}
int	main (int argc, char **argv)
{
	
	if (argc == 2)
	{
		camel_to_snake(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}