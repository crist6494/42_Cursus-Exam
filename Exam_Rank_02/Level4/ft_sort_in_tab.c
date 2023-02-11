/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:04:56 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/22 00:42:14 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe la siguiente función:
void sort_int_tab(int *tab, unsigned int size);
Debe ordenar (in-place) el array int 'tab', que contiene exactamente 'size'
en orden ascendente.
Los dobles deben ser preservados.
La entrada es siempre coherente. */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	aux;

	while (i < size)
	{
		if(tab[i] > tab[i + 1])
		{
			aux = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = aux;
			i = 0;
		}
		else
			i++;
	}
	
}

#include <stdio.h>

int main(void)
{
    int tab[10];
    int i = 0;

    tab[0] = 9;
    tab[1] = 2;
    tab[2] = 4;
    tab[3] = 3;
    tab[4] = 3;
    tab[5] = 0;
    tab[6] = 11111;
    tab[7] = 7;
    tab[8] = 5;
    tab[9] = 6;
    sort_int_tab(tab, 9);
    while (i <= 9)
        printf("%d\n", tab[i++]);
    return (0);
}