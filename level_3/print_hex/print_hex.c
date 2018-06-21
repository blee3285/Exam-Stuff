/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:22:40 by blee              #+#    #+#             */
/*   Updated: 2018/06/15 20:26:16 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(int num)
{
	int		i;
	char	hex[] = "0123456789abcdef";

	i = num % 16;
	if (num / 16)
		print_hex(num / 16);
	if ((i >= 0) && (i < 16))
		ft_putchar(hex[i]);
}

int		ft_atoi(char *str)
{
	int idx;
	int neg;
	int num;

	idx = 0;
	neg = 1;
	num = 0;
	while ((str[idx] == ' ') || (str[idx] == '\t') || (str[idx] == '\n') ||
			(str[idx] == '\v') || (str[idx] == '\f') || (str[idx] == '\r'))
		idx++;
	if (str[idx] == '-')
		neg = -1;
	if ((str[idx] == '-') || (str[idx] == '+'))
		idx++;
	while ((str[idx] >= '0') && (str[idx] <= '9'))
	{
		num *= 10;
		num += (str[idx] - '0');
		idx++;
	}
	return (num * neg);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	ft_putchar('\n');
	return (0);
}
