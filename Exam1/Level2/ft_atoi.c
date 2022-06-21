/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:45:55 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/21 19:00:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La función atoi() en C toma una cadena (que representa un número entero) como argumento y
// devuelve su valor de tipo int.

#include <unistd.h>

int	ft_atoi(const char *str)
{
	size_t	pos;
	size_t	neg;
	size_t	num;

	pos = 0;
	neg = 1;
	num = 0;

	while ((str[pos] >= 9 && str[pos] <= 13) || str[pos] == 32)
		pos++;
	if (str[pos] == '-')
	{
		neg *= -1;
		pos++;
	}
	else if (str[pos] == '+')
		pos++;
	while(str[pos] >= '0' && str[pos] <= '9')
	{
		num = num * 10 + (str[pos] - '0');
		pos++;
	}
	num *= neg;
	return (num);
}
	
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", ft_atoi(argv[1]));
	return (0);
}