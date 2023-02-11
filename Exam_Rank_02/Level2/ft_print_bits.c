/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:00:18 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/20 23:09:53 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Escriba una función que tome un byte, y lo imprima en binario

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char bit;
	int i = 8;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
	
}
int	main(void)
{
	print_bits(12);
	write(1, "\n", 1);
}