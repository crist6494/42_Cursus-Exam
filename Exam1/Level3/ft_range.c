/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:37:18 by cristian          #+#    #+#             */
/*   Updated: 2022/06/27 18:06:37 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe la siguiente función:
int *ft_range(int inicio, int fin);
Debe asignar (con malloc()) un array de enteros, llenarlo con valores consecutivos
consecutivos que comiencen en el inicio y terminen en el final (¡Incluyendo el inicio y el final!), y luego
devolver un puntero al primer valor del array */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*ptr;
	int	pos;


	pos = 0;
	ptr = (int *)malloc(sizeof(int) * (end - start));
	if (ptr)
	{
		while (start <= end)
		{
			ptr[pos] = start;
			pos++;
			start++;
		}
		return (ptr);
	}
	return (0);
}

#include <stdio.h>
int main()
{
	int *arr = ft_range(-3, -1);
	for(int i = 0; i < 3; i++)
		printf("%d", arr[i]);
}
