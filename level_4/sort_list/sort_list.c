/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:34:44 by blee              #+#    #+#             */
/*   Updated: 2019/11/04 19:24:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void    swap_list(t_list *prev, t_list *current, t_list *after)
{
    if (!prev)
    {
        current->next = after->next;
        after->next = current;
    }
    else
    {
        prev->next = after;
        current->next = after->next;
        after->next = current;
    }
}

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *prev;
    t_list  *current;
    t_list  *after;
    int     loop;
    int     sorted;

    sorted = 0;
    loop = 1;
    prev = 0;
    current = lst;
    after = lst->next;
    while (loop)
    {
        loop = 0;
        current = lst;
        while (current)
        {
            after = current->next;
            sorted = cmp(current->data, after->data);
            if (!sorted)
            {
                loop = 1;
                if (current == lst)
                    lst = after;
                swap_list(prev, current, after);
                prev = after;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    return (lst);
}
