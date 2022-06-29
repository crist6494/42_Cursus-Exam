/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:30:23 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/29 17:43:24 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba una función que tome una cadena, la divida en palabras y las devuelva como
una matriz de cadenas terminada en NULL.
Una "palabra" se define como una parte de una cadena delimitada por espacios/tablillas/nuevas
o por el inicio/fin de la cadena. */

#include <stdlib.h>
#include <stdio.h>


char	**ft_split(char *str)
{
	int	i;
	int	i2;
	int	i3;
	char **esp;

 	i = 0;
	i2 = 0;
	esp = (char**)malloc(sizeof(char) * 100);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] > ' ')
		{
			i3 = 0;
			esp[i2] = (char*)malloc(sizeof(char) * 100);
			while (str[i] > ' ')
			{
				esp[i2][i3] =str[i];
				i++;
				i3++;
			}
			esp[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	esp[i2] = 0;
	return (esp);
}

int main(int ac, char **av)
{
	char **str;
	if (ac == 2)
		str = ft_split(av[1]);
	int i = -1;
	while (str[++i] != NULL)
	{
		printf("%s\n", str[i]);
	}
	return (0);
}