/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:00:54 by blee              #+#    #+#             */
/*   Updated: 2017/05/02 14:54:32 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(int value, int base)
{
	int i;

	i = 0;
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
	int	i;

	i = value % base;
	return (num[i]);
}

char    *ft_itoa_base(int value, int base)
{
	char	*str;
	int	len;
	int	neg;

	neg = 0;
	if ((value < 0) && (base == 10))
	{
		neg = 1;
		value *= -1;
	}
	len = ft_strlen(value, base);
	if (neg)
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
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
