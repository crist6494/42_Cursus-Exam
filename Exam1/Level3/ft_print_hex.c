/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:12:48 by cmorales          #+#    #+#             */
/*   Updated: 2022/10/03 19:16:58 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome un número positivo (o cero) expresado en base 10
y lo muestre en base 16 (letras minúsculas) seguido de una nueva línea.
Si el número de parámetros no es 1, el programa muestra una nueva línea
 */

#include <unistd.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	pos;
	int	num;
	
	pos = 0;
	num = 0;
	while (str[pos])
	{
		num = num * 10 + (str[pos] - '0');
		pos++;
	}
	return (num);
}

void	ft_print_hex(int num)
{
	char	*base;

	base = "0123456789abcdef";

	if (num >= 16)
	{
		ft_print_hex(num / 16);
		ft_print_hex(num % 16);
	}
	else
		ft_putchar(base[num % 16]);
	
}

int	main (int argc, char **argv)
{ 
	if (argc == 2)
	{
		ft_print_hex(ft_atoi(argv[1]));
	}
	return (0);
}