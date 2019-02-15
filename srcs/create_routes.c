/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:28:15 by oespion           #+#    #+#             */
/*   Updated: 2019/02/15 11:06:35 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int         ft_check(t_solve *routes, char *end_name)
{
	t_solve *tmp;

	tmp = routes;
	while (tmp)
	{
		if (tmp->path->current->name == end_name)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				more_one(t_road *road)
{
	if (road->current->link->next)
		return (1);
	return (0);
}

t_solve     *new_turn(t_solve *solution, t_map *map)
{
	t_solve	*tmp;
	t_solve *end;
	t_solve *add;
	t_road	*road;
	t_solve	*new;
	t_solve	*last;

	tmp = solution;
	end = solution;
	while (end->next)
		end = end->next;
	add = end;
	while (tmp != end)
	{
		if (more_one(tmp->path))
		{
			while (tmp->path->current->link)
			{
				if (!(road = (t_road*)malloc(sizeof(t_road))))
					exit(-1);
				road->prev = tmp->path;
				road->current = tmp->path->current->link->node;
				if (!tmp->path->current->link->next)
					tmp->path = road;
				else
				{
					if (!(new = (t_solve*)malloc(sizeof(t_solve))))
						exit(-1);
					new->path = road;
					new->next = NULL;
					add->next = new;
					add = new;
				}
				tmp->path->current->link = tmp->path->current->link->next;
			}
		}
		else
		{
			if (!(road = (t_road*)malloc(sizeof(t_road))))
				exit(-1);
			road->prev = tmp->path;
			road->current = tmp->path->current->link->node;

			tmp->path = road;
		}
		ft_printf("->%s\n", tmp->path->current->name);
		tmp = tmp->next;
	}
	return solution;
}

t_solve     *create_routes(t_map *map, int max_roads, t_solve * routes)
{
	while (42)
	{
		if (ft_check(routes, map->end->name))
			break;
		routes = new_turn(routes, map);
		exit(-1);
	}
	return routes;
}
