/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rostring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:14:03 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/29 17:52:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba un programa que tome una cadena y muestre esta cadena después de rotarla
una palabra a la izquierda.
Así, la primera palabra se convierte en la última, y las demás permanecen en el mismo orden.
Una "palabra" se define como una parte de una cadena delimitada por espacios/tapas, o
por el inicio/fin de la cadena.
Las palabras estarán separadas por un solo espacio en la salida.
Si hay menos de un argumento, el programa muestra \n */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	**ft_split(char *str)
{
	int	i;
	int	i2;
	int	i3;
	char **esp;

	i = 0;
	i2 = 0;
	esp = (char **)malloc(sizeof(char) * 100);
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
				esp[i2][i3] = str[i];
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

int	main (int argc, char **argv)
{
	int	i;
	char **esp;

	i = 1;
	if (argc > 1)
	{
		esp = ft_split(argv[1]);
		while (esp[i])
		{
			ft_putstr(esp[i]);
			write (1, " ", 1);
			i++;
		}
		ft_putstr(esp[0]);
	}
	write (1, "\n", 1);
	return (0);
}