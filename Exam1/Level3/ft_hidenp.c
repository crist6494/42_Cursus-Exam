/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidenp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:05:41 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/25 16:46:58 by cristian         ###   ########.fr       */
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

void	hidenp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		while (*s1 != *s2 && *s2 != '\0')
			s2++;
		if (*s2 == '\0')
		{
			write(1, "0", 1);
			return;
		}
		s2++;
		s1++;
	}
	write(1, "1", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
