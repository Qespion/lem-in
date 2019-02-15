/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:28:15 by oespion           #+#    #+#             */
/*   Updated: 2019/02/15 21:30:50 by oespion          ###   ########.fr       */
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

t_solve		*ft_add_end(t_solve *add_end, t_map *map, t_solve *solution)
{
	t_solve	*tmp;

	tmp = solution;
	while (tmp)
	{
		if (tmp->path->current->link->node != tmp->path->prev->current)
			tmp = tmp->next;
		if (!tmp->next)
		{
			//todo
		}
		tmp = tmp->next;
	}
	return (add_end);
}

t_solve     *new_turn(t_solve *solution, t_map *map)
{
	t_solve	*tmp;
	t_solve	*end;
	t_solve	*add_end;

	tmp = solution;
	end = solution;
	while (end->next)
		end = end->next;
	add_end = end;
	while (tmp != end)
	{
		add_end = ft_add_end(add_end, map, tmp);
		tmp = tmp->next;
	}
	add_end = ft_add_end(add_end, map, tmp);
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
