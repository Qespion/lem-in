/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:12:36 by avo               #+#    #+#             */
/*   Updated: 2018/08/30 15:54:15 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	map = parse_map(ac, av);
	free(map);
	return (0);
}
