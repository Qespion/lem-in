/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_island.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:37:06 by oespion           #+#    #+#             */
/*   Updated: 2018/08/28 18:54:09 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	create_island(char *str, t_map *map, int m_limits)
{
	t_node	*new_node;

	if (str[0] != '#')
	{
		if (!(t_node*)malloc(sizeof(new_node)))
			exit(-1);
		new_node->name = str;
	}
}