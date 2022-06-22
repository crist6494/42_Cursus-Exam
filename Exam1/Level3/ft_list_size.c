/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:56:41 by cristian          #+#    #+#             */
/*   Updated: 2022/06/22 11:15:09 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe una función que devuelva el número de elementos de la lista enlazada que se
que se le ha pasado.
Debe ser declarada como sigue:
int ft_list_size(t_list *begin_list);
Debe utilizar la siguiente estructura, y entregarla como un archivo llamado
ft_list.h: */

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list -> next));
}
 #include <stdio.h>
 #include <stdlib.h>

 int	main(void)
 {
 	int n = 0;

 	t_list *c = malloc(sizeof(t_list));
 	c->next = 0;
 	c->data = &n;

 	t_list *b = malloc(sizeof(t_list));
 	b->next = c;
 	b->data = &n;

 	t_list *a = malloc(sizeof(t_list));
 	a->next = b;
 	a->data = &n;

 	printf("%d\n", ft_list_size(a));
 }