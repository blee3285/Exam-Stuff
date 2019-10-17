/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:13:02 by blee              #+#    #+#             */
/*   Updated: 2019/10/16 18:37:47 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_numlen(num)
{
    int     i;

    i = 0;
    if (num <= 0)
    {
        i++;
        num = num * -1;
    }
    while (num > 0)
    {
        num /= 10;
        i++;
    }
    return (i);
}

void    ft_strcpy(char *dst, const char *src)
{
    int     i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
}

char    *neg_max(void)
{
    char    *str;

    str = (char*)malloc(sizeof(char) * 12);
    ft_strcpy(str, "-2147483648");
    return (str);
}

char    *ft_itoa(int nbr)
{
    int     neg;
    int     len;
    char    *str;

    if (nbr == -2147483648)
        return (neg_max());
    neg = nbr * -1;
    len = ft_numlen(nbr);
    if (nbr < 0)
        nbr *= -1;
    str = (char*)malloc(sizeof(char) * (len + 1));
    str[len] = 0;
    len--;
    if (nbr == 0)
        str[0] = '0';
    while (nbr > 0)
    {
        str[len] = (nbr % 10) + '0';
        len--;
        nbr /= 10;
    }
    if (neg)
        str[len] = '-';
    return (str);
}
