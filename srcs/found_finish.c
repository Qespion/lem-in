/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:23:40 by oespion           #+#    #+#             */
/*   Updated: 2019/02/22 18:05:20 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_solve		*remove_finish_line(t_solve *solution, t_map *map)
{
	t_solve	*tmp;

	tmp = solution;
	while (tmp)
	{
		if (tmp == map->end)
			solution = solution->next;
		if (tmp->next == map->end)
		{
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}
	return (solution);
}

t_wroad		*found_finish_line(t_solve *solution, t_map *map, t_wroad *wroad)
{
	t_wroad	*new_node;
	t_wroad	*tmp;
	tmp = wroad;
	while (solution)
	{
		if (solution->path->current == map->end)
		{
			if (!(new_node = (t_wroad*)malloc(sizeof(t_wroad))))
				exit(-1);
			new_node->path = solution->path;
			new_node->next = NULL;
			if (!wroad)
			{
				wroad = new_node;
				tmp = new_node;
			}
			else
			{
				while (wroad->next)
					wroad = wroad->next;
				wroad->next = new_node;
			}
		}
		solution = solution->next;
	}
	return (tmp);
}

int			enough_wroad(t_wroad *wroad, t_map *map, t_solve *solution, int max_roads)
{
	int		len_wroad;
	int		len_road;
	t_wroad	*tmp;
	t_solve	*tmp_solve;

	len_wroad = 0;
	len_road = 0;
	tmp = wroad;
	tmp_solve = solution;
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
	ft_printf("len wroad %d\n", len_wroad);
	if (len_wroad >= max_roads)
		return (1);
	if (len_road == 0)
		return (1);
	if (len_wroad >= map->nb)
		return (1);
	return (0);
}
