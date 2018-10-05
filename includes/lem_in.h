/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:14:40 by avo               #+#    #+#             */
/*   Updated: 2018/08/28 18:53:23 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_m
{
	struct s_m	*next;
	char		*dest;
}				t_m;

typedef struct	s_node
{
	char		*name;
	t_m			*road;
}				t_node;

typedef struct s_map
{
	t_node		*node;
	t_node		*start;
	t_node		*end;
	int			ants;
}				t_map;

t_map			*parse_map(int ac, char **av);

#endif