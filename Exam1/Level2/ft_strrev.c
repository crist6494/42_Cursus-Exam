/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:17:18 by cristian          #+#    #+#             */
/*   Updated: 2022/06/19 16:14:18 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función strrev() es una función integrada en C y se define en el archivo de encabezado string.h.
La función strrev() se usa para invertir la cadena dada.*/

int	ft_strlen(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		pos++;
	}
	return (pos);
}
char	*ft_strrev(char *str)
{
	int	pos;
	int	len;
	char	aux;
	
	pos = 0;
	aux = 0;
	len = ft_strlen(str);
	len--;
	while (len > pos)
	{
		aux = str[len];
		str[len] = str[pos];
		str[pos] = aux;
		pos++;
		len--;
	}	
	return (str);
}

#include <stdio.h>

int	main()
{
	char str[] = "Hola";
	printf("%s", ft_strrev(str));
}