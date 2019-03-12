/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:28:15 by oespion           #+#    #+#             */
/*   Updated: 2019/03/12 10:04:11 by avo              ###   ########.fr       */
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

t_solve		*ft_add_end(t_map *map, t_solve *tmp, t_solve *solution)
{
	t_solve	*tmp_solve;
	t_link	*tmp_link;
	t_road	*road;
	t_solve *new_solve;
	t_solve *add_end;

	tmp_solve = tmp;
	tmp_link = tmp_solve->path->current->link;
	add_end = tmp;
	while (add_end->next)
		add_end = add_end->next;
	while (tmp_link)
	{
		if (tmp_link->node == tmp->path->prev->current)
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
	solution = ft_del_one_solve(solution, tmp);
	return (solution);
}

t_solve		*new_turn(t_solve *solution, t_map *map, t_wroad *wroad, int max_roads)
{
	int		turn;
	t_solve	*tmp;
	t_solve	*end;

	turn = 0;
	tmp = solution;
	end = solution;
	while (end->next)
		end = end->next;
	while (!enough_wroad(wroad, map, solution, max_roads))
	{
		while (tmp != end)
		{
			solution = ft_add_end(map, tmp, solution);
			tmp = tmp->next;
		}
		solution = ft_add_end(map, tmp, solution);
		turn += 1;
		ft_printf("turn : %d\n\n", turn);
		while (end->next)
			end = end->next;
		read_current(solution);
		wroad = found_finish_line(solution, map, wroad);
		solution = remove_line(solution, map);
		read_current(solution);		
		tmp = solution;
	}
	// print_working_roads(wroad, map);
	wroad = ft_find_conflict(wroad, map);
	ft_create_group(wroad, map, max_roads);
	ft_printf("found solution\n");
	return solution;
}

t_solve     *create_routes(t_map *map, int max_roads, t_solve * routes)
{
	t_wroad	*wroad;
	wroad = NULL;
	
	routes = new_turn(routes, map, wroad, max_roads);
	return (routes);
}
