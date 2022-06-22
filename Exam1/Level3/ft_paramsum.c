/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramsum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:53:49 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/22 19:04:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que muestre el número de argumentos que se le pasan, seguido de
una nueva línea.
Si no hay argumentos, sólo muestra un 0 seguido de una nueva línea. */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

int	main (int argc, char **argv)
{
	(void)argv;
	argc--;
	ft_putnbr(argc);
	ft_putchar('\n');
	return (0);
}