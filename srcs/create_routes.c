/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:28:15 by oespion           #+#    #+#             */
/*   Updated: 2019/02/18 18:48:55 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		read_current(t_solve *solution)
{
	ft_printf("--current state\n");
	while (solution)
	{
		ft_printf("%s\n", solution->path->current->name);
		solution = solution->next;
	}
	ft_printf("------\n");
}

int		found_finish_line(t_solve *solution, t_map *map)
{
	while (solution)
	{
		if (solution->path->current == map->end)
		{
			ft_printf("\n\n BOYS WE FOUND SOMETHING\n--\n");
			return (1);
		}
		solution = solution->next;
	}
	return (0);
}

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
	t_solve	*tmp_solve;
	t_link	*tmp_link;
	t_road	*road;
	t_solve *new_solve;

	tmp_solve = solution;
	tmp_link = tmp_solve->path->current->link;
	while (tmp_link)
	{
		if (tmp_link->node == solution->path->prev->current)
		{
			tmp_link = tmp_link->next;
			continue;
		}
		if (!(new_solve = (t_solve*)malloc(sizeof(t_solve))))
			exit(-1);
		if (!(road = (t_road*)malloc(sizeof(t_road))))
			exit(-1);
		road->current = tmp_link->node;
		road->prev = tmp_solve->path;
		new_solve->next = NULL;
		new_solve->path = road;
		add_end->next = new_solve;
		add_end = add_end->next;
		tmp_link = tmp_link->next;
	}
	return (add_end);
}

t_solve     *new_turn(t_solve *solution, t_map *map)
{
	t_solve	*tmp;
	t_solve	*end;
	t_solve	*add_end;

	int	turn = 0;
	tmp = solution;
	end = solution;
	while (end->next)
		end = end->next;
	add_end = end;
	while (!found_finish_line(solution, map))
	{
		while (tmp != end)
		{
			add_end = ft_add_end(add_end, map, tmp);
			tmp = tmp->next;
		}
		turn += 1;
		ft_printf("turn : %d\n\n", turn);
		end = add_end;
		read_current(solution);
		tmp = solution;
	}
	add_end = ft_add_end(add_end, map, tmp);
	return solution;
}

t_solve     *create_routes(t_map *map, int max_roads, t_solve * routes)
{
	routes = new_turn(routes, map);
	return routes;
}
