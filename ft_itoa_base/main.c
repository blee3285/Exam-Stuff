/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:42:42 by blee              #+#    #+#             */
/*   Updated: 2017/05/02 14:46:38 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_itoa_base(int value, int base);

int	main(int ac, char **av)
{
	char *str;

	if (ac == 3)
	{
		str = ft_itoa_base(atoi(av[1]), atoi(av[2]));
		printf("%s\n", str);
	}
	return (0);
}
