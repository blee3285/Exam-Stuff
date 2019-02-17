/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:28:13 by blee              #+#    #+#             */
/*   Updated: 2019/02/16 16:35:49 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		i;
	char	c;

	i = 0;
	if (ac == 2)
	{
		while(av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				c = av[1][i] - 'a';
				c = ((c + 1) % 26) + 'a';
				ft_putchar(c);
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				c = av[1][i] - 'A';
				c = ((c + 1) % 26) + 'A';
				ft_putchar(c);
			}
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
