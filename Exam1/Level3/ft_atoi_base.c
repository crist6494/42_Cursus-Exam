/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:52:21 by cristian          #+#    #+#             */
/*   Updated: 2022/06/28 17:28:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Escribe una función que convierta el argumento cadena str (base N <= 16)
a un número entero (base 10) y lo devuelva.
Los caracteres reconocidos en la entrada son 0123456789abcdef
Por supuesto, hay que recortarlos según la base solicitada. Para
ejemplo, la base 4 reconoce "0123" y la base 16 reconoce "0123456789abcdef".
Las letras mayúsculas también deben ser reconocidas: "12fdb3" es lo mismo que "12FDB3".
Los signos menos ('-') sólo se interpretan si son el primer carácter de la
cadena. */

char	ft_to_lower(char c)
{
	if (c >='A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int	get_digit(char c, int digit_base)
{
	int	max_digit;
	
	if (digit_base <= 10)
		max_digit = digit_base + '0';
	else
		max_digit = digit_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else 
		return (-1);
}
int	ft_atoi_base(const char *str, int str_base)
{
	int result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;	
	}
	while ((digit = get_digit(ft_to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		str++;
	}	
	return (result);
}

#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	int		nb;
	if (ac >= 3)
	{
		nb = ft_atoi_base(av[1], atoi(av[2]));
		printf("%d\n", nb);
	}
	return (0);
}