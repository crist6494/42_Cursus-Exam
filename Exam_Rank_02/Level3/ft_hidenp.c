/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidenp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:05:41 by cmorales          #+#    #+#             */
/*   Updated: 2022/09/29 19:35:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa llamado hidenp que tome dos cadenas y muestre 1
seguido de una nueva línea si la primera cadena está oculta en la segunda,
en caso contrario muestra 0 seguido de una nueva línea.
Sean s1 y s2 cadenas. Decimos que s1 está oculta en s2 si es posible
encontrar cada carácter de s1 en s2, en el mismo orden en que aparecen en s1.
Además, la cadena vacía está oculta en cualquier cadena.
Si el número de parámetros no es 2, el programa muestra una nueva línea.
Traducción realizada con la versión gratuita del traductor www.DeepL.com/Translator */

#include <unistd.h>

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	
	if (argc == 3)
	{
		while (argv[2][j] && argv[1][i])
		{
			if (argv[2][j] == argv[1][i])
				i++;
			j++;
		}
		if (argv[1][i] == '\0')
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
