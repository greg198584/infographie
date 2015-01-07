/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:04:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/07 09:00:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"

void    ft_mlx_draw_line(t_mlxenv *e, t_mlxp p, t_mlxp p2)
{
	int		l;
	float	xy[5];
	float	incxy[5];
	int		i;

	l = (ABS(p2.y - p.y) > ABS(p2.x - p.x)) ? ABS(p2.y - p.y) : ABS(p2.x - p.x);
	incxy[X] = (float)(p2.x - p.x) / (float)l;
	incxy[Y] = (float)(p2.y - p.y) / (float)l;
	incxy[2] = (float)(ft_get_color(p2.rgb, GET_COLOR_RED) - ft_get_color(p.rgb,
				GET_COLOR_RED)) / (float)l;
	incxy[3] = (float)(ft_get_color(p2.rgb, GET_COLOR_GREEN) -
				ft_get_color(p.rgb, GET_COLOR_GREEN)) / (float)l;
	incxy[4] = (float)(ft_get_color(p2.rgb, GET_COLOR_BLUE) -
				ft_get_color(p.rgb, GET_COLOR_BLUE)) / (float)l;
	xy[X] = p.x + 0.5;
	xy[Y] = p.y + 0.5;
	xy[2] = ft_get_color(p.rgb, GET_COLOR_RED) + 0.1;
	xy[3] = ft_get_color(p.rgb, GET_COLOR_GREEN) + 0.1;
	xy[4] = ft_get_color(p.rgb, GET_COLOR_BLUE) + 0.1;
	while (l-- >= 0 && (i = -1))
	{
		mlx_pixel_put(e->mlx, e->win, (int)xy[X], (int)xy[Y],
						ft_get_rgb((int)xy[2], (int)xy[3], (int)xy[4]));
	while (++i < 5)
		xy[i] = xy[i] + incxy[i];
	}
}
