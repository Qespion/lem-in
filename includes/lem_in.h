/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:14:40 by avo               #+#    #+#             */
/*   Updated: 2019/01/04 15:38:22 by oespion          ###   ########.fr       */
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
	struct s_node	*jcpu;
	struct s_node	*start;
	struct s_node	*end;
	struct s_node	*begin;
}					t_map;

t_map	*get_file(char *file);

#endif