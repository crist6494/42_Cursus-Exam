/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_of_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:34:21 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/20 17:47:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe una función que determine si un número dado es una potencia de 2.
Esta función devuelve 1 si el número dado es una potencia de 2,
en caso contrario devuelve 0. Su función debe ser declarada como sigue:
int es_poder_de_2(unsigned int n); */

int     is_power_of_2(unsigned int n)
{
	int	pos;

	pos = 1;
	while (pos <= n)
	{
		if (pos == n)
			return (1);
		pos = pos * 2;	
	}
	return (0);
}

#include <stdio.h>

int main()
{
	printf ("%d",(is_power_of_2(1) ? printf("Yes\n") : printf("No\n")));
	return (0);
}