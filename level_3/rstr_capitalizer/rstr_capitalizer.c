/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:59:18 by blee              #+#    #+#             */
/*   Updated: 2019/02/16 17:29:46 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	upper_case(char c)
{
	if (c >= 'a' && c <= 'z')
		ft_putchar(c - ('a' - 'A'));
	else
		ft_putchar(c);
}

void	lower_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		ft_putchar(c + ('a' - 'A'));
	else
		ft_putchar(c);
}

void	rstr_cap(char *str)
{
	if (!*str)
		return ;
	if (!*(str + 1) || *(str + 1) == ' ' || *(str + 1) == '\t'
			|| *(str + 1) == '\n')
	{
		upper_case(*str);
		rstr_cap(str + 1);
	}
	else if (*str)
	{
		lower_case(*str);
		rstr_cap(str + 1);
	}
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		while(av[i])
		{
			rstr_cap(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
