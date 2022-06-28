/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:39:46 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/28 19:11:13 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escriba una función que tome un int y lo convierta en una cadena terminada en cero.
La función devuelve el resultado en un array de caracteres que debe asignar.
Su función debe ser declarada como sigue:
char *ft_itoa(int nbr); */

#include <stdlib.h>

int	ft_sign(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	get_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char *result;
	int	len;

	len = get_len(num);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';

	if (num < 0)
		result[0] = '-';
	else if (num == 0)
		result[0] = '0';
	while (num != 0)
	{
		len--;
		result[len] = ft_sign(num % 10) + '0';
		num = num / 10;
	}
	return (result);
}

 #include <stdio.h>
 #include <limits.h>

 int	main(void)
  {
	 	int d = INT_MIN;
  	printf("%d =? %s\n", d, ft_itoa(d));

 	d = -14;
	 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 0;
	 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 5;
	 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = INT_MAX;
	 	printf("%d =? %s\n", d, ft_itoa(d));
	 }