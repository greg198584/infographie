/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:31:16 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/13 16:16:48 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

static void	ft_write_wall(t_game *e, int x)
{
	int				i;
	int				wall_l;
	int				y;
	unsigned int	color;
	unsigned char	*wall;

	color = mlx_get_color_value(e->mlx, COLOR_WALL + (e->move->range_k * 8));
	wall_l = (HEIGHT / (2 * e->move->range_k));
	y = ((HEIGHT / 2) * e->pic->sizeline) + (x * e->pic->bpp / 8);
	wall = (unsigned char *)&color;
	i = -1;
	while (++i < wall_l)
	{
		ft_pixel_to_img(e->pic, wall, y - (i * e->pic->sizeline));
		ft_pixel_to_img(e->pic, wall, y + (i * e->pic->sizeline));
	}
}

void	ft_display_wall(t_game *e)
{
	float	x;
	float	y;
	float	i;

	i = -1;
	while (++i <= WIDTH)
	{
		y = (((WIDTH / 2) - i) / WIDTH);
		x = (0.5 * e->move->cos_ang[e->move->id_ang]) -
			(y * e->move->sin_ang[e->move->id_ang]);
		y = (0.5 * e->move->sin_ang[e->move->id_ang]) +
			(y * e->move->cos_ang[e->move->id_ang]);
		x += e->move->pos->x;
		y += e->move->pos->y;
		e->move->range_k = ft_range(e, x, y);
		ft_write_wall(e, i);
	}
}
