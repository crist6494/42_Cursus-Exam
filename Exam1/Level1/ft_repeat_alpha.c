/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:27:06 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/16 17:15:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa llamado repetir_alfa que tome una cadena y la muestre
repitiendo cada carácter alfabético tantas veces como su índice alfabético
seguido de una nueva línea.
'a' se convierte en 'a', 'b' se convierte en 'bb', 'e' se convierte en 'eeeee', etc...
El caso no cambia.
Si el número de argumentos no es 1, sólo se muestra una nueva línea. */

#include <unistd.h>

int	main (int argc, char **argv)
{
	int	letter = 0;
	int	repeat = 0;
	
	if (argc == 2)
	{
		while (argv[1][letter])
		{
			if(argv[1][letter] >= 'a' && argv[1][letter] <= 'z')
				repeat = argv[1][letter] + repeat - 'a' + 1;
			else if(argv[1][letter] >= 'A' && argv[1][letter] <= 'Z')
			repeat = argv[1][letter] + repeat - 'A' + 1;
			while (repeat)
			{
				write(1, &argv[1][letter], 1);
				repeat--;
			}
			letter++;
		}
	}
	write (1, "\n", 1);
	return (0);
}