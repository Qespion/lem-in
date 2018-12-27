/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:14:40 by avo               #+#    #+#             */
/*   Updated: 2018/11/24 22:50:40 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct		s_link
{
	char			*lname;
	struct s_link	*link;
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
}					t_map;

t_map	*get_file(char *file);

#endif