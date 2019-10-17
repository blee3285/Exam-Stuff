/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:56:41 by blee              #+#    #+#             */
/*   Updated: 2019/10/16 17:08:29 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     is_power_of_2(unsigned int n)
{
    unsigned int    i = 1;

    while (i <= n)
    {
        if (i == n)
            return (1);
        i = i * 2;
    }
    return (0);
}
