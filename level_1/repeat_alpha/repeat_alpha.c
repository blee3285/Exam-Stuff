/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:23:48 by blee              #+#    #+#             */
/*   Updated: 2018/06/15 17:42:55 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_repeat(char c, int num)
{
	while (num > 0)
	{
		ft_putchar(c);
		num--;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		repeat;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				repeat = av[1][i] - 'a' + 1;
				print_repeat(av[1][i], repeat);
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				repeat = av[1][i] - 'A' + 1;
				print_repeat(av[1][i], repeat);
			}
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
