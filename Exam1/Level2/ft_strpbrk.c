/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:47:37 by cristian          #+#    #+#             */
/*   Updated: 2022/06/22 10:23:52 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La función strpbkr () encuentra el primer carácter en la cadena s1 
que coincide con cualquier carácter especificado en s2
(excluye la terminación de caracteres nulos).*/

#include <string.h>

char	find_char(const char c, const char *s1)
{
	int	pos;
	
	pos = 0;
	while (s1[pos])
	{
		if (s1[pos] == c)
			return (1);
		pos++;
	}
   return (0);
}
char	*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		if(find_char(*s1, s2) == 1)
			return ((char *) s1);
		   s1++;
	}
	return (0);
}

 #include <stdio.h>
 #include <string.h>

int main () {
   const char str1[] = "34";
   const char str2[] = "4";
   char *ret;

   ret = strpbrk(str1, str2);
   if(ret) {
      printf("First matching character: %c\n", *ret);
   } else {
      printf("Character not found");
   }
    ret = ft_strpbrk(str1, str2);
   if(ret) {
      printf("First matching character: %c\n", *ret);
   } else {
      printf("Character not found");
   }
   return(0);
}
