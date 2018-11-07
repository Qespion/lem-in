/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:12:36 by avo               #+#    #+#             */
/*   Updated: 2018/11/03 13:25:17 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

/*
** function get_file == GNL => understand where to go | lemin nb
** create node with start and end
** create link in each node
*/

int	main(int ac, char **av)
{
	t_map *map;

	if (ac != 2)
	{
		ft_printf("Touloooonnnn\n");
		return (1);
	}
	map = get_file(av[1]);
	return (0);
}
