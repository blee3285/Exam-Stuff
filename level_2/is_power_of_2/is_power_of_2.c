/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:17:47 by blee              #+#    #+#             */
/*   Updated: 2019/02/05 18:24:39 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_power_of_2(unsigned int n)
{
	unsigned int	i;

	i = 2;
	while (i <= n)
	{
		if (i == n)
			return (1);
		i = i * 2;
	}
	return (0);
}