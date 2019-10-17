/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:18:50 by blee              #+#    #+#             */
/*   Updated: 2019/10/16 17:53:12 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_bits(unsigned char octet)
{
    int     i;
    char    c;

    i = 128;
    c = 0;
    while (i > 0)
    {
        c = octet / i;
        octet = octet % i;
        ft_putchar(c + '0');
        i /= 2;
    }
}
