/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:56:12 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/15 20:07:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* copia la cadena src a dst (incluyendo el carácter de terminación "0").ter).
 */

char *ft_strcpy(char * dst, const char * src)
{
	int	pos;

	pos = 0;
	while (dst[pos])
	{
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
	return (dst);
}

#include <stdio.h>
int	main ()
{
	char src[] = "pepepepepe";
	char dst[] = "Hola que tal";

	printf("%s", ft_strcpy(dst, src));
}