/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:59:10 by blee              #+#    #+#             */
/*   Updated: 2019/01/31 18:27:21 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int		*ft_rrange(int start, int end)
{
	int		size;
	int		temp;
	int		i;
	int		*range;

	size = end - start;
	i = 0;
	if (size > 0)
	{
		range = (int*)malloc(sizeof(int) * (size + 1));
		temp = end;
		size = size + 1;
		while (i < size)
		{
			range[i] = temp;
			i++;
			temp--;
		}
	}
	else if (size < 0)
	{
		range = (int*)malloc(sizeof(int) * (ft_abs(size) + 1));
		temp = end;
		size = ft_abs(size) + 1;
		while (i < size)
		{
			range[i] = temp;
			i++;
			temp++;
		}
	}
	else
	{
		range = (int*)malloc(sizeof(int));
		range[0] = start;
	}
	return (range);
}
