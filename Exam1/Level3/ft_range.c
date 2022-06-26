/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:37:18 by cristian          #+#    #+#             */
/*   Updated: 2022/06/26 23:03:42 by cristian         ###   ########.fr       */
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
	int	size;
	int	*ptr;
	int	*aux;

	size = end - start;
	if (size)
	{
		ptr = (int *)malloc(sizeof(int) * size);
		if (ptr)
		{
			aux = ptr;
			while (start <= end)
			{
				*ptr = start;
				ptr++;
				start++;
			}
			return (aux);
		}
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
