/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:22 by oespion           #+#    #+#             */
/*   Updated: 2019/02/06 16:46:50 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

//  create routes at each nodes
//  continue routes until end island isnt found

t_solve    *create_routes(t_map *map, int max_roads)
{
    t_solve   *starting_road;
    t_road    *first;

    if (!(starting_road = (t_solve*)malloc(sizeof(t_solve))))
        exit(-1);
    if (!(first = (t_road*)malloc(sizeof(t_road))))
        exit(-1);
    first->prev = NULL;
    first->current = map->start;
    starting_road->path = first;
    return NULL;
}
