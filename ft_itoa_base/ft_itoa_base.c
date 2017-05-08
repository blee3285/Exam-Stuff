/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:29:35 by blee              #+#    #+#             */
/*   Updated: 2017/05/07 17:27:42 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_numlen(int value, int base)
{
	int		i;

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

void	build_str(char **str, int value, int base, int len)
{
	char	num[] = "0123456789ABCDEF";
	char	*temp;

	temp = *str;
	while (value && (len > -1))
	{
		len--;
		temp[len] = num[value % base];
		value /= base;
	}
}

char	*ft_strdup(char	*str)
{
	int		i;
	char	*min;

	i = 0;
	while (str[i])
		i++;
	min = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		min[i] = str[i];
		i++;
	}
	min[i] = '\0';
	return (min);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;
	int		neg;

	neg = value;
	if ((base < 2 || base > 16) || (value == -2147483648 && base != 10))
		return (ft_strdup("Error"));
	if (value < 0)
	{
		if (base == 10 && value == -2147483648)
			return (ft_strdup("-2147483648"));
		else
			value *= -1;
	}
	if (value == 0)
		return (ft_strdup("0"));
	len = ft_numlen(value, base);
	if (neg < 0)
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	build_str(&str, value, base, len);
	if (neg < 0)
		str[0] = '-';
	return (str);
}
