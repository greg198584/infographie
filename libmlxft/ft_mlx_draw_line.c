/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:04:40 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/29 19:00:51 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include <mlx.h>

void	ft_mlx_draw_line(t_mlxenv *e, t_mlxp p1, t_mlxp p2)
{
	t_mlxp	p;

	if (p1.x == p2.x)
	{
		p.y = MIN(p1.y, p2.y) - 1;
		while (++p.y < MAX(p1.y, p2.y))
			mlx_pixel_put(e->mlx, e->win, p1.x, p.y, BLUE);
		return ;
	}
	if (p1.x > p2.x)
		ft_swap_points(&p1, &p2, OPT_SWAP_XY);
	p = ft_new_point(p1.x, p1.y, p1.rgb);
	while (p.x < p2.x)
	{
		p.y = p1.y + (p2.y - p1.y)* (p.x - p1.x) / (p2.x - p1.x);
		mlx_pixel_put(e->mlx, e->win, p.x++, p.y, BLUE);
	}
}
