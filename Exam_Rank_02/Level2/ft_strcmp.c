/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:15:49 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/19 16:16:55 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La función strcmp se usa para comparar dos cadenas. Si ambas cadenas son iguales,
devuelve 0, si el primer argumento es más pequeño que el segundo según el orden definido, 
devuelve -1 y devuelve 1 cuando el segundo es más pequeño que el primero. */

int	ft_strcmp(char *s1, char *s2)
{
	int	pos;
	
	pos = 0;
	while (s1[pos] && s2[pos] && s1[pos] == s2[pos])
		pos++;
	return (s1[pos] - s2[pos]);
}

#include <stdio.h>
int	main()
{
	printf("%d", ft_strcmp("Holaa", ""));
	printf("\n%d", ft_strcmp("adiosmalas", "adiosmalas"));
}
