/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:12:14 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/15 20:24:25 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba una función que intercambie el contenido de dos enteros cuyas direcciones
se pasan como parámetros. */

void	ft_swap(int *a, int *b)
{
	int	aux;
	
	*a = aux;
	*b = *a;
	aux = *b;
}

#include <stdio.h>

int	main ()
{
	int a = 55;
	int b = 2;
	ft_swap(&a, &b);
	return (0);
}