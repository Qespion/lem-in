/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conflict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:43:09 by oespion           #+#    #+#             */
/*   Updated: 2019/03/04 16:55:55 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		ft_add_conflict(t_wroad *wroad, t_wroad *list)
{
	t_conflict	*base;
	t_conflict	*linked_base;
	t_conflict	*tmp;
	if (!(base = (t_conflict*)malloc(sizeof(t_conflict))))
		exit(-1);
	if (!(linked_base = (t_conflict*)malloc(sizeof(t_conflict))))
		exit(-1);
	base->conflict = list->nb;
	linked_base->conflict = wroad->nb;
	base->next = NULL;
	linked_base->next = NULL;
	tmp = wroad->conflict;
	if (!wroad->conflict)
		wroad->conflict = base;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = base;
	}
	
	tmp = list->conflict;
	if (!list->conflict)
		list->conflict = linked_base;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = linked_base;
	}
}

int		ft_deep_check(t_road *base_road, t_road *tmp_road, t_map *map)
{
	unsigned int		len_base;
	unsigned int		len_tmp;

	len_base = 0;
	len_tmp = 0;
	while (base_road)
	{
		len_base++;
		base_road = base_road->prev;
	}
	while (tmp_road)
	{
		len_tmp++;
		tmp_road = tmp_road->prev;
	}
	if (abs(len_base - len_tmp) > (map->nb / 2))
		return (0);
	return (1);
}

t_wroad		*check_conflict(t_wroad *wroad, t_map *map)
{
	t_wroad	*list;
	t_road	*base_road;
	t_road	*tmp_road;

	if (!wroad->next)
		return (wroad);
	list = wroad->next;
	while (list)
	{
		base_road = wroad->path;
		tmp_road = list->path;
		while (base_road)
		{
			while (tmp_road)
			{
				if (base_road->current == tmp_road->current)
				{
					if (ft_deep_check(base_road, tmp_road, map))
						ft_add_conflict(wroad, list);
				}
				tmp_road = tmp_road->prev;
			}
			base_road = base_road->prev;
		}
		list = list->next;
	}
	return (wroad);
}

void			ft_print_conflict(t_wroad *wroad)
{
	t_conflict *tmp;
	int		raod = 0;
	while (wroad)
	{
		ft_printf("\nnb %d -=", raod++);
		tmp = wroad->conflict;
		while (tmp)
		{
			ft_printf("- %d -", tmp->conflict);
			tmp = tmp->next;
		}
		wroad = wroad->next;
	}
	ft_putchar('\n');
}

t_wroad		*ft_find_conflict(t_wroad *wroad, t_map *map)
{
	t_wroad	*tmp;

	tmp = wroad;
	while (tmp)
	{
		tmp = check_conflict(tmp, map);
		tmp = tmp->next;
	}
	ft_print_conflict(wroad);
	return (wroad);
}
