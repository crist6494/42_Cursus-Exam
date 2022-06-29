/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:32:19 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/29 18:42:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe las siguientes funciones:
t_list *sort_list(t_list* lst, int (*cmp)(int, int));
Esta función debe ordenar la lista dada como parámetro, utilizando la función 
puntero cmp para seleccionar el orden a aplicar, y devuelve un puntero al 
primer elemento de la lista ordenada.
Los duplicados deben permanecer.
Las entradas serán siempre coherentes.
Debe utilizar el tipo t_list descrito en el archivo list.h 
que se le proporciona. Debe incluir ese archivo 
(#include "list.h"), pero no debe entregarlo. Utilizaremos nuestro propio 
para compilar tu tarea. */

#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	aux;
	t_list	*tmp;
	
	tmp = lst;
	while (lst->next != 0)
	{
		if ((cmp)(lst ->data, lst ->next->data) == 0)
		{
			aux = lst ->data;
			lst ->data = lst ->next->data;
			lst ->next->data = aux;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int ascending(int a, int b)
{
	return (a <= b);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	t_list *lst1;
	t_list *lst2;
	t_list *lst3;
	t_list *lst4;
	lst1 = malloc(sizeof(t_list));
	lst2 = malloc(sizeof(t_list));
	lst3 = malloc(sizeof(t_list));
	lst4 = malloc(sizeof(t_list));
	lst1->data = 1;
	lst2->data = 4;
	lst3->data = 2;
	lst4->data = 3;
	lst1->next = lst2;
	lst2->next = lst3;
	lst3->next = lst4;
	lst4->next = NULL;
	lst1=sort_list(lst1, &ascending);
	while (lst1)
	{
		printf("%d", lst1->data);
		lst1 = lst1->next;
	}
}
