/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:00:18 by cmorales          #+#    #+#             */
/*   Updated: 2022/09/22 20:28:12 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Escriba una función que tome un byte, y lo imprima en binario

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	pos;

	pos = 128;
	
	while (pos > 0)
	{
		if (octet >= pos)
		{
			write (1, "1", 1);
			octet = octet - pos;
		}
		else
		{
			write (1, "0", 1);
			pos = pos / 2;
		}
	}
}
int	main(void)
{
	print_bits(24);
	write(1, "\n", 1);
}