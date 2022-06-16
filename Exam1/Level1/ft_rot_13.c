/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_13.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:11:02 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/16 19:10:44 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome una cadena y la muestre, sustituyendo cada una de sus
letras por la letra 13 espacios más adelante en orden alfabético.
La 'z' se convierte en 'm' y la 'Z' en 'M'. Las mayúsculas y minúsculas no se ven afectadas.
La salida irá seguida de una nueva línea.
Si el número de argumentos no es 1, el programa muestra una nueva línea. */

#include <unistd.h>
int	main (int argc, char **argv)
{
	int	pos;
	
	pos = 0;
	if (argc == 2)
	{
		while (argv[1][pos])
		{
			if ((argv[1][pos] >= 'a' && argv[1][pos] <= 'm') || (argv[1][pos] >= 'A' && argv[1][pos] <= 'M'))
				argv[1][pos] = argv[1][pos] + 13;
			else if ((argv[1][pos] >= 'n' && argv[1][pos] <= 'z') || (argv[1][pos] >= 'N' && argv[1][pos] <= 'Z'))
				argv[1][pos] = argv[1][pos] - 13;
			write (1, &argv[1][pos], 1);
			pos++;
		}
	}
	write(1, "\n", 1);
	return (0);
}