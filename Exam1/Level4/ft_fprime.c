/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:54:12 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/28 18:10:23 by cmorales         ###   ########.fr       */
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
#include <unistd.h>

void	fprime(int n)
{
	int i = 2;
	if (n ==1)
			printf("1");
		while(i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n == i)
					break;
				printf("*");
				n = n / i;
				i = 2;
			}
			i++;
		}
}


int main(int argc, char **argv)
{	
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}return (0);
}
