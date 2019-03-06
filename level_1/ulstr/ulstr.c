/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:55:11 by blee              #+#    #+#             */
/*   Updated: 2019/03/05 17:00:36 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ulstr(char c)
{
	if (c >= 'A' && c <= 'Z')
		ft_putchar(c + 32);
	else if (c >= 'a' && c <= 'z')
		ft_putchar(c - 32);
	else
		ft_putchar(c);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			ulstr(av[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
