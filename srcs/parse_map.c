/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:43:08 by avo               #+#    #+#             */
/*   Updated: 2018/08/28 18:49:59 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	ants_nb(t_map *map, int fd)
{
	char	*str;
	int		r;

	get_next_line(fd, &str);
	while (str[r])
	{
		if (str[r] < '0' || str[r] > '9')
		{
			ft_printf("ERROR\n");
			free(map);
			free(str);
			exit(-1);
		}
		r++;
	}
	map->ants = ft_atoi(str);
	if (map->ants <= 0)
	{
		ft_printf("ERROR\n");
		free(map);
		ft_strdel(&str);
		exit(-1);
	}
	free(str);
}

char	*parse_island(t_map *map, int fd)
{
	char	*str;
	int		in_island;
	int		pspeplr;

	in_island = 1;
	pspeplr = 0;
	while (in_island)
	{
		get_next_line(fd, &str);
		if (strcmp(str, "##start"))
			pspeplr = 1;
		else if (strcmp(str, "##end"))
			pspeplr = 2;
		else
		{
			create_island(str, map, pspeplr);
		}
		ft_printf("str = %s\n", str);
	}
	return NULL;
}

t_map	*parse_map(int ac, char **av)
{
	int		fd;
	t_map	*map;
	char	*line;
	char	*first_sm;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	fd = open(av[1], 0);
	ants_nb(map, fd);
	first_sm = parse_island(map, fd);
	// create_sm(map, fd);
	return (map);
}
