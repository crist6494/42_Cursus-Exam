/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:07:20 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/15 20:26:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		//write (1, &str[pos], 1) == ft_putstr.c
		pos++;
	}
	return (pos);
}

#include <stdio.h>
#include <unistd.h>
int	main ()
{
	printf("%d", ft_strlen("holaaaaa"));
}