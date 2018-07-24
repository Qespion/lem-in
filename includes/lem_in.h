/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:14:40 by avo               #+#    #+#             */
/*   Updated: 2018/07/24 17:34:10 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_node
{
	int			*link;
	int			link_nb;
}				t_node;

typedef struct s_map
{
	t_node		*node;
	int			nb;
	int			ants;
}				t_map;

t_map	*parse_map(int ac, char **av);

#endif