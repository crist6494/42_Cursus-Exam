/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:12:33 by cristian          #+#    #+#             */
/*   Updated: 2022/10/05 17:43:21 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función strspn() devuelve la longitud de la subcadena inicial de la cadena a la que apunta str1
que se compone solo de los caracteres contenidos en la cadena a la que apunta str2 .*/

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	while(s[pos])
	{
		if (s[pos] == c)
			return ((char *)s);
		pos++;
	}
	return (0);
}
size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t	pos;

	pos = 0;
	while(s1[pos])
	{
		if (!ft_strchr(s2, s1[pos]))
			break;
		pos++;
	}
	return(pos);
}
 #include <stdio.h>
 int	main(void)
{
 	char s1[] = "This  this is a test string";
 	char s2[] = "This";

 	printf("%zu\n", ft_strspn(s1, s2));
 }