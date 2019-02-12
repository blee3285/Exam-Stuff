/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:14:05 by blee              #+#    #+#             */
/*   Updated: 2019/02/12 14:35:27 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		doop(int num1, int num2, char op)
{
	if (op == '+')
		return (num1 + num2);
	if (op == '-')
		return (num1 - num2);
	if (op == '*')
		return (num1 * num2);
	if (op == '/' && num2 != 0)
		return (num1 / num2);
	if (op == '%' && num2 != 0)
		return (num1 % num2);
	return (0);
}

int		main(int ac, char **av)
{
	int		num1;
	int		num2;

	if (ac == 4)
	{
		num1 = atoi(av[1]);
		num2 = atoi(av[3]);
		if (num2 == 0 && (av[2][0] == '/' || av[2][0] == '%'))
			printf("Error");
		else
			printf("%d", doop(num1, num2, av[2][0]));
	}
	printf("\n");
	return (0);
}
