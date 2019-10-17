/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:56:33 by blee              #+#    #+#             */
/*   Updated: 2019/10/16 18:09:10 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int     *range;
    int     step;
    int     size;
    int     i;

    i = 0;
    step = 1;
    if (end < start)
        step = -1;
    size = end - start;
    if (size < 0)
        size *= -1;
    range = (int*)malloc(sizeof(int) * (size + 1));
    while (start != end)
    {
        range[i] = start;
        i++;
        start += step;
    }
    range[i] = start;
    return (range);
}
