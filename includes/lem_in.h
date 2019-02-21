/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:53 by oespion           #+#    #+#             */
/*   Updated: 2019/02/21 13:31:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct		s_link
{
	struct s_node	*node;
	struct s_link	*next;
}					t_link;

typedef struct		s_node
{
	char			*name;
	struct s_link	*link;
	struct s_node	*next;
}					t_node;

typedef struct		s_map
{
	int				nb;
	struct s_node	*jcpu;  // argh
	struct s_node	*start; //starting point
	struct s_node	*end;
	struct s_node	*begin;	//start of chain
}					t_map;

typedef struct		s_road
{
	struct s_node	*current;
	struct s_road	*prev;
}					t_road;

typedef struct		s_solve
{
	struct s_road	*path;
	struct s_solve	*next;
}					t_solve;

typedef struct		s_wroad
{
	struct s_road	*path;
	struct s_wroad *next;
	int							len;
}								t_wroad;

int			get_max_roads(t_map *map);
t_map		*get_file(char *file);
t_solve		*create_base_routes(t_map *map, int max_roads);
t_solve		*create_routes(t_map *map, int max_roads, t_solve *routes);
t_solve		*ft_del_solve(t_solve *start, t_solve *todel);
t_solve 	*ft_del_one_solve(t_solve *start, t_solve *todel);
t_wroad		*found_finish_line(t_solve *solution, t_map *map, t_wroad *wroad);

#endif