/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conflict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:43:09 by oespion           #+#    #+#             */
/*   Updated: 2019/02/25 16:56:37 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_conflict	*check_conflict(t_wroad *wroad)
{
	t_conflict	*tmp_conflict;
	t_conflict	*conflict;
	t_wroad		*tmp;
	t_node		*curnode;
	t_node		*tocompare;

	tmp = wroad->next;
	curnode = tmp->path->prev->current;
	while (curnode->next)
	{
		while (tmp)
		{
			tocompare = tmp->path->current;
			while (tocompare->next)
			{
				if (tocompare == curnode)
				{
					if (!(conflict = (t_conflict*)malloc(sizeof(t_conflict))))
						exit(-1);
					conflict->next = NULL;
					conflict->conflict = tmp;
					if (!wroad->conflict)
						wroad->conflict = conflict;
					else
					{
						tmp_conflict = wroad->conflict;
						while (tmp_conflict->next)
							tmp_conflict = tmp_conflict->next;
						tmp_conflict->next = conflict;
					}
				}
				tocompare = tocompare->next;
			}
			tmp = tmp->next;
		}
		curnode = curnode->next;
	}
	return (wroad->conflict);
}

t_wroad		*ft_find_conflict(t_wroad *wroad)
{
	t_wroad	*tmp;

	tmp = wroad;
	while (tmp->next)
	{
		tmp->conflict = check_conflict(tmp);
		tmp = tmp->next;
	}
	return (wroad);
}
