/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:31:16 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/06 12:34:36 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	ft_write_wall(t_env *pr, int x)
{
	int				i;
	int				wall_l;
	int				y;
	unsigned int	color;
	unsigned char	*wall;

	color = mlx_get_color_value(pr->mlx, ID_WALL + (pr->move->range_k * 8));
	wall_l = (HEIGHT / (2 * pr->move->range_k));
	y = ((HEIGHT / 2) * pr->pic->sizeline) + (x * pr->pic->bpp / 8);
	wall = (unsigned char *)&color;
	i = -1;
	while (++i < wall_l)
	{
		(void)ft_pixel_to_img(pr->pic, wall, y - (i * pr->pic->sizeline));
		(void)ft_pixel_to_img(pr->pic, wall, y + (i * pr->pic->sizeline));
	}
}

void	ft_display_wall(t_env *pr)
{
	float x;
	float y;
	float i;

	i = -1;
	while (++i <= WIDTH)
	{
		y = (((WIDTH / 2) - i) / WIDTH);
		x = (0.5 * pr->move->cos_ang[pr->move->id_ang]) -
			(y * pr->move->sin_ang[pr->move->id_ang]);
		y = (0.5 * pr->move->sin_ang[pr->move->id_ang]) +
			(y * pr->move->cos_ang[pr->move->id_ang]);
		x += pr->move->pos->x;
		y += pr->move->pos->y;
		pr->move->range_k = ft_range(pr, x, y);
		ft_write_wall(pr, i);
	}
}
