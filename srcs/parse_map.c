/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:43:08 by avo               #+#    #+#             */
/*   Updated: 2018/07/24 17:57:07 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_map	*ants_nb(t_map *map, int fd)
{
	char	*str;

	get_next_line(fd, &str);
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			ft_printf("ERROR\n");
			free(map);
			exit(-1);
		}
		str++;
	}
	map->ants = ft_atoi(str);
	if (map->ants < 0)
	{
		ft_printf("ERROR\n");
		free(map)
		exit(-1);
	}
	return (map);
}

// todo

t_map	*get_islands(t_map *map, int fd)
{
	
}

t_map	*parse_map(int ac, char **av)
{
	int		fd;
	t_map	*map;
	char	*line;
	
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	fd = open(av[1], 0);
	map = ants_nb(map, fd);
	map = get_islands(map, fd);
	get_next_line(fd, &line);
	return (map);
}
