/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:17:23 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/28 17:50:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe una función que tome un char ** como un array bidimensional de char, un 
t_point como las dimensiones de este array y un t_point como punto de partida.
Empezando por el punto_de_inicio dado, esta función rellena una zona entera 
sustituyendo los caracteres de su interior por el carácter 'F'. Una zona es un grupo de 
un mismo carácter delimitado horizontal y verticalmente por otros caracteres
o el límite de la matriz.
La función flood_fill no rellena en diagonal.
La función flood_fill tendrá el siguiente prototipo
void flood_fill(char **tab, t_point size, t_point begin);
La estructura t_point se prototipa así*/

 typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void	fill (char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x 
	|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	fill (tab, size, begin, tab[begin.y][begin.x]);
}


#include <stdlib.h>
#include <stdio.h>
char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"11111111",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}