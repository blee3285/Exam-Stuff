/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:00:54 by blee              #+#    #+#             */
/*   Updated: 2017/05/04 14:53:03 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(int value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	next_digit(int value, int base)
{
	char	num[] = "0123456789ABCDEF";
	int		i;

	i = value % base;
	return (num[i]);
}

char	*int_min(void)
{
	int		i;
	char	*min;
	char	str[] = "-2147483648";

	i = 0;
	min = (char*)malloc(sizeof(char) * (12));
	while (str[i])
	{
		min[i] = str[i];
		i++;
	}
	min[i] = '\0';
	return (min);
}

char    *ft_itoa_base(int value, int base)
{
	char	*str;
	int	len;
	int	neg;

	neg = 0;
	if (base < 2 || base > 16)
		return ("bad base");
	if (value < 0)
	{
		if (base == 10)
		{
			neg = 1;
			if (value == -2147483648)
				return (int_min());
			value *= -1;
		}
		else
			value *= -1;
	}
	len = ft_strlen(value, base);
	if (neg)
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (value && (len > -1))
	{
		len--;
		str[len] = next_digit(value, base);
		value /= base;
	}
	if (neg)
	{
		len--;
		str[len] = '-';
	}
	if (len != 0)
		return ("error");
	return (str);
}
