/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:54:12 by cmorales          #+#    #+#             */
/*   Updated: 2022/10/27 20:28:50 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome un int positivo y muestre sus factores primos en la
salida estándar, seguida de una nueva línea.
Los factores deben mostrarse en orden ascendente y separados por '*', de modo que
la expresión en la salida dé el resultado correcto.
Si el número de parámetros no es 1, simplemente muestra una nueva línea.
La entrada, cuando la haya, será válida. */

#include <stdio.h>
#include <stdlib.h>

void	fprime( int n)
{
	int prime;
	prime = 2;

	if(n == 1)
		printf("1");
	while(prime <= n)
	{
		if(n % prime == 0)
		{
			printf("%d", prime);
			if(n == prime)
				break;
			printf("*");
			n = n / prime;
			prime = 2;
		}
		prime++;
	}
	
}
int main (int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf ("\n");
	return (0);
}