/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:07:31 by blee              #+#    #+#             */
/*   Updated: 2019/03/05 17:16:43 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		i;
	int		a;
	int		b;
	int		cd;

	i = 1;
	cd = 1;
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		while (i <= (a / 2) && i <= (b / 2))
		{
			if ((a % i) == 0 && (b % i) == 0)
				cd = i;
			i++;
		}
		printf("%d", cd);
	}
	printf("\n");
	return (0);
}
