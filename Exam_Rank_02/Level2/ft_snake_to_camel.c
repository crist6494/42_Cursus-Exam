/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snake_to_camel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:25:54 by cristian          #+#    #+#             */
/*   Updated: 2022/11/20 23:11:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	snake_to_camel(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '_')
		{
			pos++;
			str[pos] = str[pos] - 32;
		}
		write(1, &str[pos], 1);
		pos++;
	}
}
int	main(int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc == 2)
		snake_to_camel(argv[1]);
	write (1, "\n", 1);
	return (0);
}