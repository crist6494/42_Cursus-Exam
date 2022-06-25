/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:26:29 by cristian          #+#    #+#             */
/*   Updated: 2022/06/25 16:40:09 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Escriba una función que tome dos int sin signo como parámetros y devuelva el 
LCM calculado de esos parámetros.
LCM (Mínimo Común Múltiplo) de dos enteros no nulos es el menor entero positivo
entero positivo más pequeño divisible por ambos enteros.
Un LCM puede ser calculado de dos maneras:
- Se puede calcular cada uno de los múltiplos de cada uno de los enteros hasta obtener un
común que no sea 0
- Se puede utilizar el HCF (Highest Common Factor) de estos dos enteros y 
calcular como sigue:
	LCM(x, y) = | x * y | / HCF(x, y)
  | x * y | significa "Valor absoluto del producto de x por y"
Si al menos un entero es nulo, LCM es igual a 0. */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);

	unsigned int n;
	if (a > b)
		n = a;
	else
		n = b;

	while (n)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

 #include <stdio.h>

 int main(void)
 {
 	printf("%u\n", lcm(3, 8));
 }