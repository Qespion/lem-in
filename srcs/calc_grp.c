/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:56:23 by avo               #+#    #+#             */
/*   Updated: 2019/03/05 15:44:06 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		ft_wroad_len(t_wroad *wroad)
{
	int nb;

	nb = 0;
	while (wroad)
	{
		wroad = wroad->next;
		nb++;
	}
	return nb;
}

int		*init_tab(int *tab, int len)
{
	int	r;

	r = 0;
	while (r < len)
	{
		tab[r] = 0;
		r++;
	}
	return (tab);
}

int		ft_check_conflict(t_conflict *current, int r)
{
	while (current)
	{
		if (current->conflict == r)
			return (0);
		current = current->next;
	}
	return (1);
}

int		ft_get_len(int	r, t_wroad *wroad)
{
	while (r != wroad->nb)
		wroad = wroad->next;
	return (wroad->len);
}

int		ft_get_turn(t_wroad *wroad, t_wroad *current, t_map *map, int len)
{
	int	tab[len];
	int	r;

	tab[len] = init_tab(tab, len);
	r = 0;
	while (r < len)
	{
		if (ft_check_conflict(current->conflict , r))
			tab[r] = ft_get_len(r, wroad);
		r++;
	}
	//print tab
	r = 0;
	while (r < len)
	{
		ft_printf(" %d ", tab[r]);
		r++;
	}
	ft_putchar('\n');
	return (1);
}

void    ft_solve_group(t_wroad *wroad, t_map *map)
{
	unsigned int	map_nb;
	unsigned int	turn;
	t_wroad			*tmp;
	unsigned int	tmp_nb;
	int						len;

	len = ft_wroad_len(wroad);
	map_nb = 0;
	tmp = wroad;
	turn = NULL;
	while (tmp)
	{
		tmp_nb = ft_get_turn(wroad, tmp, map, len);
		if (tmp_nb < turn || turn == NULL)
		{
			turn = tmp_nb;
			map_nb = tmp->nb;
		}
		tmp = tmp->next;
	}
	ft_printf("ANNDDD THE WINNER ROAD IS %d\n", map_nb);
}
