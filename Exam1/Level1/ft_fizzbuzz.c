/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fizzbuzz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:30:45 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/15 20:07:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que imprima los números del 1 al 100, cada uno separado por una
línea nueva.
Si el número es múltiplo de 3, imprime "fizz" en su lugar.
Si el número es un múltiplo de 5, imprime "buzz" en su lugar.
Si el número es un múltiplo de 3 y un múltiplo de 5, imprime 'fizzbuzz' en su lugar. */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main()
{
	int numb;
	
	numb = 1;
	while (numb <= 100)
	{
		if (numb % 3 == 0 && numb % 5 == 0)
			write(1,"fizzbuzz", 8);
		else if (numb % 3 == 0)
			write(1, "fizz", 4);
		else if (numb % 5 == 0)
			write(1, "buzz", 4);
		else
			{
				if (numb > 9)
				{
					ft_putchar((numb / 10) + '0');
					ft_putchar((numb % 10) + '0');
				}
				else
				{
					ft_putchar (numb + '0');
				}
			}
			write (1, "\n", 1);
			numb++;	
	}
	return (0);
}