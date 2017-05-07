/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:24:47 by blee              #+#    #+#             */
/*   Updated: 2017/05/07 15:30:29 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		open_b(char c)
{
	char	valid[] = "({[";
	int		i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (valid[i]);
		i++;
	}
	return (0);
}

int		close_b(char c)
{
	char	ret[] = "({[";
	char	valid[] = ")}]";
	int		i;

	i = 0;
	while (valid[i])
	{
		if (valid[i] == c)
			return (ret[i]);
		i++;
	}
	return (0);
}

int		brackets(char *str)
{
	int		i;
	char	*temp;
	char	hold[ft_strlen(str) + 1];

	i = 0;
	temp = str;
	*hold = 0;
	while (*temp)
	{
		if (open_b(*temp))
		{
			hold[i] = *temp;
			i++;
		}
		if (close_b(*temp) == hold[i - 1] && temp > str)
		{
			i--;
			hold[i] = 0;
		}
		temp++;
	}
	temp--;
	if (*hold == 0)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (brackets(av[i]))
				ft_putstr("OK");
			else
				ft_putstr("Error");
			i++;
		}
	}
	ft_putstr("\n");
	return (0);
}
