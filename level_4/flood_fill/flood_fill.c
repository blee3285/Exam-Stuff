/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:17:12 by blee              #+#    #+#             */
/*   Updated: 2019/01/23 18:37:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	filler(char **tab, t_point size, int x, int y, char c)
{
	char	*temp;

	temp = *tab;
	if (x < 0 || x > size.x || y < 0 || y > size.y)
		return ;
	if (temp[y][x] == c)
	{
		temp[y][x] = 'F';
		filler(tab, size, x + 1, y, c);
		filler(tab, size, x - 1, y, c);
		filler(tab, size, x, y + 1, c);
		filler(tab, size, x, y - 1, c);
	}
	else
		return ;
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	*temp;
	char	c;

	temp = *tab;
	c = tab[begin.y][begin.x];
	filler(tab, size, begin.x, begin.y, c);
}
