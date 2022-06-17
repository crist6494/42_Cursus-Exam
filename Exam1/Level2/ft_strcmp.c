/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:15:49 by cmorales          #+#    #+#             */
/*   Updated: 2022/06/17 19:23:35 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
