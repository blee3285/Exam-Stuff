/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:36:22 by blee              #+#    #+#             */
/*   Updated: 2019/02/22 15:38:40 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int num)
{
	int		mod;

	mod = 2;
	while ((num / mod) >= mod)
	{
		if (num % mod == 0)
		{
			printf("%d*", mod);
			num /= mod;
		}
		else
		{
			if (mod == 2)
				mod++;
			else
				mod += 2;
		}
	}
	printf("%d", num);
}

int		main(int ac, char **av)
{
	int		num;

	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num == 1)
			printf("1");
		else
			fprime(num);
	}
	printf("\n");
	return (0);
}
