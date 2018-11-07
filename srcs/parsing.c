/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:19:22 by avo               #+#    #+#             */
/*   Updated: 2018/11/04 17:00:57 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	get_ants(char *str, int *turn, t_map ***map, int *border)
{
	if (str[0] == '#' && str[1] != '#')
		return ;
	if (ft_strlen(str) > 13 || ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648
		|| ((ft_atoi(str) == 0 && str[0] != '0')))
	{
		ft_printf("404 on lemmins\n");
		exit(-1);
	}
	(**map)->nb = ft_atoi(str);
	ft_printf("%d\n", (**map)->nb);
	*turn += 1;
}

void	get_roads(char *str, int *turn, t_map ***map, int *border)
{
	ft_printf("in roads \n");
	return ;
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

void	get_island(char *str, int *turn, t_map ***map, int *border)
{
	t_node	*new_node;

	// if (*turn == 1 || *turn == 2)
	// {
	// 	*turn = (*turn == 1 ? 10 : 20);
	// 	return ; 
	// }
	if (str[0] == '#' && str[1] != '#')
	4	return ;
	if(!(new_node = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	if ((**map)->jcpu)
	{
		ft_printf("MAPjcpu =============%S\n", (**map)->jcpu);
		new_node->next = (**map)->jcpu;
	}
	(**map)->jcpu = new_node;
	new_node->name = ft_strsub(str, 0, find_space(str));
	new_node->link = NULL;
	ft_printf("new naode name = %s\n", new_node->name);
}

int		where_am_i(char *str, int turn)
{
	if (turn == 1 && ft_strstr(str, "-"))
		return (2);
	return (turn);
}

int		find_border(char *str, int border)
{
	if (!ft_strcmp("##start", str))
		return (1);
	else if (!ft_strcmp("##end", str))
		return (border == 1 ? 3 : 2);
	return (0);	
}

void	read_file(t_map **map, char *file)
{
	static int	border;
	static int	turn;
	int			fd;
	char		*str;
	void		(*parse[2])(char *, int *, t_map ***, int *border);

	turn = 0;
	border = 0;
	fd = open(file, 0);
	parse[0] = get_ants;
	parse[1] = get_island;
	parse[2] = get_roads;
	while (get_next_line(fd, &str))
	{
		turn = where_am_i(str, turn);
		border = find_border(str, border);
		ft_printf("%s\n", str);
		ft_printf("border %d\n", border);
		ft_printf("turn %d\n", turn);
		parse[turn](str, &turn, &map, &border);
	}
}

t_map	*get_file(char *file)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	map->jcpu = NULL;
	map->start = NULL;
	map->end = NULL;
	read_file(&map, file);
	ft_printf("%d\n", map->nb);
	ft_printf("%s\n", map->jcpu);
	ft_printf("%s\n", map->jcpu);
	return (map);
}
