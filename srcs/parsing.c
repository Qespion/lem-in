/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:08:41 by avo               #+#    #+#             */
/*   Updated: 2018/12/18 15:09:13 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_map   *get_ants(char *str, int *turn, t_map *map, int border)
{
	if (str[0] == '#' && str[1] != '#')
	{
		map->nb = -42;
		return (map);
	}
	if (ft_strlen(str) > 13 || ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648
		|| ((ft_atoi(str) == 0 && str[0] != '0')))
	{
		ft_printf("404 on lemmins");
		exit(-1);
	}
	else if (ft_atoi(str) < 0)
	{
		ft_printf("Negative numbers of lemmins");
		exit(-1);
	}
	map->nb = ft_atoi(str);
	return (map);
}

int		find_space(char *str)
{
	int	r;

	r = 0;
	while (str[r])
	{
		if (str[r] == ' ')
			return (r);
		r++;
	}
	return (0);
}

t_map   *get_island(char *str, int *turn, t_map *map, int border)
{
	t_node	*new_node;
	if (str[0] == '#' && str[1] != '#')
		return (map);
	else if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
		return (map);
	if (!(new_node = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	if (!(new_node->name = (char *)malloc(sizeof((char) * ft_strsub(str, 0, find_space(str))))))
		exit(-1);
	new_node->name = ft_strsub(str, 0, find_space(str));
	new_node->link = NULL;
	if (!map->jcpu)
		map->jcpu = new_node;
	else
	{
		map->jcpu->next = new_node;
		map->jcpu = new_node;
	}
	if (border == 1)
		map->start = new_node;
	else if (border == 2)
		map->end = new_node;
	return (map);
}


t_map   *get_road(char *str, int *turn, t_map *map, int border)
{
	if (str[0] == '#' && str[1] != '#')
		return (map);
}

int		where_am_i(char *str, int turn, t_map *map)
{
	if (str[0] == '#' && str[1] != '#')
		return (turn);
	else if (turn == 0 && (map->nb != -42 || !map->nb))
		return (1);
	else if (turn == 1 && ft_strstr(str, "-"))
		return (2);
	// FIX THAT 
	else if (!ft_strchr(str, '-'))
	{
		ft_printf("tu marches ?\n");
		exit(-1);
	}
	return (turn);
}

int		find_border(char *str, int border)
{
	if (!ft_strcmp("##start", str))
		return (1);
	else if (!ft_strcmp("##end", str))
	{
		if (border == 1)
		{
			ft_printf("start is end\n");
			exit(-1);
		}
		return (2);
	}
	return (0);
}

t_map	*read_file(t_map *map, char *file)
{
	static int	border;
	static int	turn;
	int			fd;
	char		*str;
	t_map		*(*parse[2])(char *, int *, t_map *, int border);

	turn = 0;
	border = 0;
	fd = open(file, 0);
	parse[0] = get_ants;
	parse[1] = get_island;
	parse[2] = get_road;
	while (get_next_line(fd, &str))
	{
		turn = where_am_i(str, turn, map);
		// ft_printf("%s\n", str);
		// ft_printf("border %d\n", border);
		// ft_printf("turn %d\n", turn);
		parse[turn](str, &turn, map, border);
		border = find_border(str, border);
	}
	return (map);
}

t_map	*get_file(char *file)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	map->jcpu = NULL;
	map->start = NULL;
	map->end = NULL;
	map = read_file(map, file);
	// ft_printf("%d\n", map->nb);
	// ft_printf("%s\n", map->jcpu);
	ft_printf("%s\n", map->jcpu->name);
	ft_printf("%s\n", map->start->name);
	return (map);
}