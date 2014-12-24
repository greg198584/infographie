/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 14:03:54 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 15:15:29 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"

int	ft_mlx_draw_map(t_mlxenv *e)
{
	t_mlxp	p1;
	int		x_size;
	int		y_size;
	int		square;

	square = e->square;
	x_size = WIN_X / 200 * e->x_size;
	y_size = WIN_Y / 200 * e->y_size;
	p1 = ft_new_point(WIN_X / 2 - x_size, WIN_Y / 2 - y_size, BLUE);
	while (p1.x <= (WIN_X / 2 + x_size))
	{
		ft_mlx_draw_line(e, p1, ft_new_point(p1.x, p1.y + 2 * y_size, 0));
		p1.x += square;
	}
	p1.x = WIN_Y / 2 - x_size;
	while (p1.y <= (WIN_Y / 2 + y_size))
	{
		ft_mlx_draw_line(e, p1, ft_new_point(p1.x + 2 * x_size, p1.y, 0));
		p1.y += square;
	}
	return (0);
}
