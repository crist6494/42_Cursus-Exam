/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:45:31 by cmorales          #+#    #+#             */
/*   Updated: 2022/11/22 00:54:04 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome una cadena como parámetro e imprima sus palabras en 
en orden inverso.
Una "palabra" es una parte de la cadena delimitada por espacios y/o tabulaciones, o el 
inicio/fin de la cadena.
Si el número de parámetros es diferente de 1, el programa mostrará 
'\n'.
En los parámetros que se van a probar, no habrá ningún espacio "adicional" 
espacios "adicionales" (es decir, no habrá espacios adicionales ni al principio ni al 
al principio o al final de la cadena, y las palabras siempre 
estarán separadas exactamente por un espacio).
 */

#include <unistd.h>

void	ft_rev_wstr(char *str)
{
	int	i;
	int	j;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{	
		while (i >= 0 && (str[i] == '\0' || str[i] == ' ' || str[i] == '\t'))
			i--;
		j = i;
		while (j >= 0 && str[j] != ' ' && str[j] != '\t')
			j--;
		if (space == 1)
			write (1, " ", 1);
		write (1, str + j + 1, i - j);
		space = 1;
		i = j;
	}
}

int	main (int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev_wstr(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}