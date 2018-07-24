/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:12:36 by avo               #+#    #+#             */
/*   Updated: 2018/07/24 17:20:28 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	map = parse_map(ac, av);
	return (0);
}
