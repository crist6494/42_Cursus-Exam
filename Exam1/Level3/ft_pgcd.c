/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:19:50 by cristian          #+#    #+#             */
/*   Updated: 2022/06/25 16:17:58 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome dos cadenas que representen dos enteros estrictamente positivos
enteros que caben en un int.
Muestra su máximo común denominador seguido de una nueva línea (Siempre es un
entero estrictamente positivo).
Si el número de parámetros no es 2, muestra una nueva línea. */

#include <unistd.h>
#include <stdio.h>

int atoi (char *str)
{
	int	pos;
	int num;

	num = 0;
	pos = 0;
	while (str[pos])
	{
		num = num *10 + (str[pos] - '0');
		pos++;
	} 
	return (num);
}
void	pgcd(int a, int b)
{
	int num;

	num = a;
	while (num > 0)
	{
		if (a % num == 0 && b % num == 0)
		{
			printf("%d", num);
			return;
		}
		num--;
	}
}
int	main (int argc, char **argv)
{
	if (argc == 3)
	{
		pgcd(atoi(argv[1]), atoi(argv[2]));
	}
	write (1, "\n", 1);
	return (0);
}