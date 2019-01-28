/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:32:22 by blee              #+#    #+#             */
/*   Updated: 2019/01/28 14:01:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

char	*ft_newstr(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str)
	{
		new[i] = *str;
		str++;
		i++;
	}
	new[i] = '\n';
	return (new);
}

void	print_area(char **area, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while(area[i][j] != '\n')
		{
			write(1, &area[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(void)
{
	char	**area;
	t_point	size = { 8, 5 };
	t_point	begin = { 2, 2 };

	area = (char**)malloc(sizeof(char**) * 5);
	area[0] = ft_newstr("11111111");
	area[1] = ft_newstr("10001001");
	area[2] = ft_newstr("10010001");
	area[3] = ft_newstr("10110001");
	area[4] = ft_newstr("11100001");
	print_area(area, 5);
	write(1, "\n", 1);
	flood_fill(area, size, begin);
	print_area(area, 5);
	return (0);
}
