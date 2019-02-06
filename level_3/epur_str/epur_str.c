/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:11:48 by blee              #+#    #+#             */
/*   Updated: 2019/02/05 15:35:49 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else if (c == '\0')
		return (-1);
	else
		return (0);
}

int		is_end(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			return (1);
		else if (is_space(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 2)
	{
		while (is_space(av[1][i]) == 1)
			i++;
		while (av[1][i])
		{
			if (is_space(av[1][i]) == 0)
				ft_putchar(av[1][i]);
			else if (is_space(av[1][i]) == 1)
			{
				if (is_end(&av[1][i]) == 0)
					ft_putchar(' ');
				while (is_space(av[1][i]) == 1)
					i++;
				i--;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
