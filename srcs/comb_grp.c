/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:10:06 by avo               #+#    #+#             */
/*   Updated: 2019/03/10 17:30:15 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	ft_print_line(int *line, int len)
{
	int r = 0;
	while (r <= len)
	{
		ft_printf("%d - ", line[r++]);
	}
	ft_printf("\n");
}

int     *set_zero(int *roads, int len)
{
	int r;

	r = 0;
	while (r <= len)
	{
		roads[r] = 0;
		r++;
	}
	return (roads);
}

int		*try_line(int **tab, int len, int *line, int index)
{
	int	r;
	int *tmp_line;
	r = 0;

	if (!(tmp_line = (int*)malloc(sizeof(int) * (len + 1))))
		exit(-1);
	tmp_line = set_zero(tmp_line, len);
	while (r < len)
	{
		if (r == index)
		{
			r++;
			continue;
		}
		// if (line[r] != 0)
		// 	line = check  
		r++;
	}
	ft_print_line(line, len);
	return (line);
}

int    *bt_grp(int **tab, int len)
{
	int *line;
	int r;

	r = 0;
	if (!(line = (int*)malloc(sizeof(int) * (len + 1))))
		exit(-1);
	line = set_zero(line, len);
	while (r < len)
	{
		line = try_line(tab, len, line, r);
		r++;
	}
	return (line);
}
