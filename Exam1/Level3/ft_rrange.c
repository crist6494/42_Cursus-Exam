/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:57:29 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/27 19:23:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe la siguiente función:
int *ft_rrange(int inicio, int fin);
Debe asignar (con malloc()) un array de enteros, llenarlo con valores consecutivos
consecutivos que empiecen por el final y terminen por el inicio (¡incluyendo el inicio y el final!), y luego
devolver un puntero al primer valor del array. */

#include <stdlib.h>

int	ft_check(int	s)
{
	if (s < 0)
		return (-s);
	else
		return (s);
}
int	*ft_rrange(int start, int end)
{
	int	*ptr;
	int	pos;

	pos = 0;
	ptr = (int *)malloc(sizeof(int) * ft_check(end - start) + 1);
	if (start < end)
	{
		while (end >= start)
		{
			ptr[pos] = end;
			end--;
			pos++;
		}
	}
	else if (start > end)
	{
		while (end <= start)
		{
			ptr[pos] = end;
			end++;
			pos++;
		}
	}
	return (ptr); 
}
	
#include <stdio.h>
 
int main()
{
	int i = 0;
	int *res = ft_rrange(0, -3);
	while (i < 4)
	{
		printf("%d,", res[i]);
		i++;
	}
	printf("\n");
}