/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:10:52 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/19 14:23:52 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La función strdup () devuelve un puntero a una nueva cadena que es
un duplicado de la cadena s . La memoria para la nueva cadena es
obtenido con malloc(3) , y se puede liberar con free(3) . */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	pos;
	pos	= 0;
	

	while(str[pos])
		pos++;
	return (0);
}
char	*strdup(const char *s1)
{
	int	pos;
	char	*s2;
	int	len;
	
	pos = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * len + 1);

	while (s1[pos])
	{
		s2[pos] = s1[pos];
		pos++;
	}
	s2[pos] = '\0';
	return (s2);
}
#include<stdio.h>
#include<string.h>
 
int main()
{
   char	s1 [20] = "Hola buenas tardes";
   char	*s2;
   s2 = strdup (s1);
   printf("%s", s1);
   printf("\n");
   printf("%s", s2);
}