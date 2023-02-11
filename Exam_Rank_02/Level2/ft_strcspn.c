

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:31:30 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/17 20:07:58 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La función strcspn  () calcula la longitud del segmento inicial de str1,
que consiste completamente en caracteres que no están en str2 .*/

#include <unistd.h>

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	pos;
	size_t	pos2;

	pos = 0;
	pos2 = 0;
	while (s1[pos])
	{
		pos2 = 0;
		while (s2[pos2])
		{
			if (s1[pos] == s2[pos2])
				return (pos);
			pos2++;
		}
		pos++;
	}
	return (pos);
}
#include <string.h>
#include <stdio.h>
int main ()
{
	char *s1;
	char *s2;
	s1 = "Hheoeelllo";
	s2 = "oe";
printf("%zu\n",ft_strcspn(s1, s2));
printf("%zu\n",strcspn(s1, s2));
}