/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_mirror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:38:46 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/20 18:10:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa llamado alpha_mirror que tome una cadena y muestre esta cadena
después de reemplazar cada carácter alfabético por el carácter alfabético opuesto
opuesto, seguido de una nueva línea.
La 'a' se convierte en 'z', la 'Z' se convierte en 'A'
la 'd' se convierte en 'w', la 'M' se convierte en 'N'
 */
#include <unistd.h>

int	main (int argc, char **argv)
{
	int pos;

	pos = 0;
	if (argc == 2)
	{
		while (argv[1][pos])
		{
			if(argv[1][pos] >= 'a' && argv[1][pos] <= 'z')
				argv[1][pos] = 'm' - (argv[1][pos] - 'n');
			else if(argv[1][pos] >= 'A' && argv[1][pos] <= 'z')
				argv[1][pos] = 'M' - (argv[1][pos] - 'N');
			write (1, &argv[1][pos], 1);
			pos++;
		}
	}
	write (1,"\n",1);
	return (0);
}