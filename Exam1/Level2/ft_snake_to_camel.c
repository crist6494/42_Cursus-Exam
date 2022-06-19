/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snake_to_camel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:25:54 by cristian          #+#    #+#             */
/*   Updated: 2022/06/19 17:32:54 by cristian         ###   ########.fr       */
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
	{
		snake_to_camel(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}