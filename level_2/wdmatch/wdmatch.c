/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:11:05 by blee              #+#    #+#             */
/*   Updated: 2018/06/15 19:04:37 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		wdmatch(char *a, char *b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (a[i] && b[j])
	{
		if (a[i] == b[j])
			i++;
		j++;
	}
	if (a[i])
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		if (wdmatch(av[1], av[2]))
			ft_putstr(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
