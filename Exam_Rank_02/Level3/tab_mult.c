/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:02:28 by cristian          #+#    #+#             */
/*   Updated: 2022/06/25 14:15:56 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que muestre la tabla de multiplicación de un número.
El parámetro será siempre un número estrictamente positivo que cabe en un int,
y dicho número multiplicado por 9 también cabe en un int.
Si no hay parámetros, el programa muestra \n.
Si no hay argumentos, el programa debe mostrar \n. */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int pos;
	int num;

	pos = 0;
	num = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		num = num * 10 + (str[pos] - '0');
		pos++;
	}
	return (num);
}

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr (num % 10);	
	}
	else
		ft_putchar (num + '0');
}

void tab_mult(char *str)
{
	int pos;
	int num;
	
	pos = 1;
	num = ft_atoi(str);
	while (pos <= 9)
	{
		ft_putnbr(pos);
		write (1, " x ", 3);
		ft_putnbr(num);
		write (1, " = ", 3);
		ft_putnbr(pos * num);
		write (1, "\n", 1);
		pos++;
	}
}
int	main (int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write (1, "\n", 1);
}