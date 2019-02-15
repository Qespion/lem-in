/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:22 by oespion           #+#    #+#             */
/*   Updated: 2019/02/15 19:05:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

//  create base routes at start

t_road	*start_road(t_map *map)
{
	t_road	*road;
	if (!(road = (t_road*)malloc(sizeof(t_road))))
		exit(-1);
	road->prev = NULL;
	road->current = map->start;
	return (road);
}

t_solve     *get_first_roads(t_solve *solution, t_map *map)
{
	t_link		*tmp;
	t_road		*road;
	t_solve		*next_sol;
	t_solve		*start;

	tmp = map->start->link;
	start = solution;
	while (tmp)
	{
		if (!(road = (t_road*)malloc(sizeof(t_road))))
			exit(-1);
		road-> current = tmp->node;
		road->prev = start_road(map);
		if (!solution->path)
			solution->path = road;
		else
		{
			if (!(next_sol = (t_solve*)malloc(sizeof(t_solve))))
				exit(-1);
			solution->next = next_sol;
			next_sol->path = road;
			next_sol->next = NULL;
			solution = next_sol;
		}
		tmp = tmp->next;
	}
	return start;
}

t_solve    *create_base_routes(t_map *map, int max_roads)
{
    t_solve   *solution;

	if (!(solution = (t_solve*)malloc(sizeof(t_solve))))
        exit(-1);
    solution->path = NULL;
    solution->next = NULL;
    solution = get_first_roads(solution, map);
    // while (solution)
	// {
	// 	ft_printf("%s\n", solution->path->current->name);
	// 	ft_printf("test\n");
	// 	solution = solution->next;
	// }
	// exit(-1);
	return solution;
}