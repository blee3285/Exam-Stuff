/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:33:09 by blee              #+#    #+#             */
/*   Updated: 2019/01/28 13:50:16 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H 

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif
