/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:47:01 by cmorales          #+#    #+#             */
/*   Updated: 2022/09/29 19:52:46 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe un programa que tome tres cadenas:
- La primera y la tercera son representaciones de enteros con signo de base-10
  que caben en un int.
- La segunda es un operador aritmético elegido entre: + - * / %

El programa debe mostrar el resultado de la operación aritmética solicitada,
seguido de una nueva línea. Si el número de parámetros no es 3, el programa
sólo muestra una nueva línea.

Se puede asumir que la cadena no tiene errores ni caracteres extraños. Los números negativos de
en la entrada o en la salida, tendrán uno y sólo un '-' inicial. El
resultado de la operación cabe en un int. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1]) - atoi(argv[3])));
		if (argv[2][0] == '*')
			printf("%d", (atoi(argv[1]) * atoi(argv[3])));
		if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		if (argv[2][0] == '%')
			printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	}
	printf("\n");
	return (0);
}