/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_prime_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:50:23 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/21 20:10:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome un número entero positivo como argumento y muestre la suma
de todos los números primos inferiores o iguales a él, seguida de una nueva línea.
Si el número de argumentos no es 1, o el argumento no es un número positivo
simplemente muestra 0 seguido de una nueva línea.
Sí, los ejemplos son correcto */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int num;
	int	pos;
	
	pos = 0;
	num = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		num = num * 10;
		num = num + (str[pos] - '0');
		pos++;
	}
	return (num);
}

void	ft_putnbr(int num)
{
	char 	c;
	
	if(num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
	} else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}


int		is_prime(int n)
{
	int pos = 2;

	while (pos < n)
	{
		if (n % pos == 0)
			return (0);
		pos++;
	}
	return (1);
}

int		add_prime_sum(int n)
{
	int sum = 0;
	int pos = 2;

	while (pos <= n)
	{
		if (is_prime(pos) == 1)
			sum = sum + pos;
		pos++;
	}
	return (sum);
}

int		main(int argc, char **argv)
{
	int num;

	if (argc == 2 && (num = ft_atoi(argv[1])))
		ft_putnbr(add_prime_sum(num));
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}