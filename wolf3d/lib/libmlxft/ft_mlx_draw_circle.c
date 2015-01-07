/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:38:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/07 08:05:23 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"

void	ft_mlx_draw_circle(t_mlxenv *e, t_mlxp p, int r, int opt)
{
	int xy[2];
	int d;

	xy[0] = 0;
	xy[1] = r;
	d = r - 1;
	while (xy[1] >= xy[0])
	{
		mlx_pixel_put(e->mlx, e->win, p.x + xy[0], p.y + xy[1], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[1], p.y + xy[0], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[0], p.y + xy[1], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[1], p.y + xy[0], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[0], p.y - xy[1], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[1], p.y - xy[0], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[0], p.y - xy[1], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[1], p.y - xy[0], p.rgb);
		if (d >= (2 * xy[0]))
			d = d - (2 * xy[0]++) - 1;
		else if (d < (2 * (r - xy[1])))
			d = d + (2 * xy[1]--) - 1;
		else
			d = d + (2 * (xy[1]-- - xy[0]++ - 1));
	}
	if (r > 0 && opt > 0)
		ft_mlx_draw_circle(e, p, r - 1, opt - 1);
}
