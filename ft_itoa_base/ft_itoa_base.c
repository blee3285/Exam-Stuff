/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:29:35 by blee              #+#    #+#             */
/*   Updated: 2017/05/08 17:21:21 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_numlen(long long value, int base)
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

char	*ft_strdup(char *str)
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

char	*build_str(long long value, int base, int len)
{
	char	*num;
	char	*temp;

	num = ft_strdup("0123456789ABCDEF");
	temp = (char*)malloc(sizeof(char) * (len + 1));
	temp[len] = '\0';
	while (value && (len > -1))
	{
		len--;
		temp[len] = num[value % base];
		value /= base;
	}
	if (len != 0)
		temp[0] = '-';
	free(num);
	return (temp);
}

char	*ft_itoa_base(int value, int base)
{
	long long	num;
	char		*str;
	int			len;
	int			neg;

	num = value;
	neg = 0;
	if (base == 10)
		neg = value;
	if (base < 2 || base > 16)
		return (ft_strdup("Error"));
	if (num < 0)
			num *= -1;
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_numlen(num, base);
	if (neg < 0)
		len++;
	str = build_str(num, base, len);
	return (str);
}
