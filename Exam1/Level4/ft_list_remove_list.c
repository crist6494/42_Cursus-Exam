/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:31:16 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/28 19:50:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba una función llamada ft_list_remove_if que elimine de la
lista pasada cualquier elemento cuyos datos sean "iguales" a los de la referencia.
Se declarará como sigue :
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
cmp toma dos void* y devuelve 0 cuando ambos parámetros son iguales.
Hay que utilizar el fichero ft_list.h, que contendrá: */

#include "ft_list.h"
#include <stdlib.h>

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*current;
	t_list		*previous;

	previous = 0;
	current = *begin_list;
	while (current)
	{
		if ((cmp)(current->data, data_ref) == 0)
		{
			if (previous == 0)
				*begin_list = current->next;
			else
				previous->next = current->next;
			free(current);
		}
		previous = current;
		current = current->next;
	}
}
