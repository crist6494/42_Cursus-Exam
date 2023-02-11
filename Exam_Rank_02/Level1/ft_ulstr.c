/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:56:20 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/16 20:04:40 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome una cadena e invierta las mayúsculas y minúsculas de todas sus letras.
Los demás caracteres no se modifican.
Debe mostrar el resultado seguido de un '\n'.
Si el número de argumentos no es 1, el programa muestra '\n'.. */

#include <unistd.h>

int	main (int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc == 2)
	{
		while (argv[1][pos])
		{
			if (argv[1][pos] >= 'a' && argv[1][pos] <= 'z')
				argv[1][pos] = argv[1][pos] - 32;
			else if (argv[1][pos] >= 'A' && argv[1][pos] <= 'Z')
				argv[1][pos] = argv[1][pos] + 32;
			write (1, &argv[1][pos], 1);
			pos++;
		}
	} 
	write (1, "\n", 1);
	return (0);
}