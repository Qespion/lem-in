/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:23:40 by oespion           #+#    #+#             */
/*   Updated: 2019/02/21 14:14:09 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_wroad		*found_finish_line(t_solve *solution, t_map *map, t_wroad *wroad)
{
	return NULL;	
}

int				enough_wroad(t_wroad *wroad, t_map *map, t_solve *solution, int max_roads)
{
	int		len_wroad;
	int		len_road;
	t_wroad	*tmp;
	t_solve		*tmp_solve;

	len_wroad = 0;
	len_road = 0;
	while (tmp)
	{
		len_wroad++;
		tmp = tmp->next;
	}
	while (tmp_solve)
	{
		len_road++;
		tmp_solve = tmp_solve->next;
	}
	if (len_wroad >= max_roads)
		return (1);
	if (len_road = 0)
		return (1);
	if (len_wroad > map->nb)
		return (1);
	return (0);
}
