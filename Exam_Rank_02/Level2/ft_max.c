/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:35:31 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/20 18:52:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe la siguiente función:
int max(int* tab, unsigned int len);
El primer parámetro es un array de int, el segundo es el número de elementos en
la matriz.
La función devuelve el mayor número encontrado en el array. */

int ft_max(int *tab, unsigned int len)
{
	int	pos;
	int	max;

	pos = 0;
	max = 0;
	while (pos < len)
	{
		if (tab[pos] > max)
			max = tab[pos];
		pos++;
	}
	return (max);
}

#include <stdio.h>
int	main ()
{
	int	numbers[5] = {1, 2, 4544, 889};
	printf ("%d", ft_max(numbers, 2));
}