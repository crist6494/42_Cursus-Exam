/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:22:07 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/28 19:29:11 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba una función que tome una lista y un puntero de función, y aplique esta
función a cada elemento de la lista.
Debe ser declarada como sigue:
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
La función apuntada por f se utilizará de la siguiente manera:
(*f)(lista_ptr->datos);*/

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list == 0)
		return ;
	while (begin_list != 0)
	{
		f(begin_list->data);
		begin_list = begin_list ->next;
	}
}

#include <stdio.h>
#include <stdlib.h>

 void	int_doubler(void *n)
  {
	 	int *num = (int *)n;
  	*num = *num * 2;
  }

 int		main(void)
  {
	 	t_list *pt_a = malloc(sizeof(t_list));
  	int	n_a = 0;
  	pt_a->data = &n_a;
  	pt_a->next = 0;

 	t_list *pt_b = malloc(sizeof(t_list));
	 	int	n_b = 3;
	 	pt_b->data = &n_b;
	 	pt_b->next = 0;

 	t_list *pt_c = malloc(sizeof(t_list));
	 	int	n_c = 4;
	 	pt_c->data = &n_c;
	 	pt_c->next = 0;

 	pt_a->next = pt_b;
	 	pt_b->next = pt_c;

 	t_list *cur = pt_a;
	 	while (cur != 0)
	 	{
		 		printf("%d, ", *(int *)(cur->data));
	 		cur = cur->next;
	 	}
	 	printf("\n");

 	ft_list_foreach(pt_a, int_doubler);

 	cur = pt_a;
	 	while (cur != 0)
	 	{
		 		printf("%d, ", *(int *)(cur->data));
	 		cur = cur->next;
	 	}
	 	printf("\n");
	 }
