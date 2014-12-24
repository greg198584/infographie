/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:24:14 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 16:25:51 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"

void	ft_draw_case_one(t_data *d, char *data)
{
	int	x;
	int	mod_x;
	int	mod_y;
	int	max;

	if (d->x1 < d->x2)
	{
		x = d->x1;
		max = d->x2;
	}
	else
	{
		x = d->x2;
		max = d->x1;
	}
	while (x <= max)
	{
		mod_x = x;
		mod_y = ((d->y1 + ((d->y2 - d->y1) *
				(x - d->x1) / (d->x2 - d->x1))));
		if (mod_x > 0 && mod_x < 1650 && mod_y > 0 && mod_y < 1000)
			ft_pixel_put(d, data, mod_x * d->bpp / 8, mod_y * d->sizelin);
		x++;
	}
}

void	ft_draw_case_two(t_data *d, char *data)
{
	int	y;
	int	mod_x;
	int	mod_y;
	int	max;

	if (d->y1 < d->y2)
	{
		y = d->y1;
		max = d->y2;
	}
	else
	{
		y = d->y2;
		max = d->y1;
	}
	while (y <= max)
	{
		mod_x = y;
		mod_y = ((d->x1 + ((d->x2 - d->x1) *
						(y - d->y1) / (d->y2 - d->y1))));
		if (mod_x > 0 && mod_x < 1000 && mod_y > 0 && mod_y < 1650)
			ft_pixel_put(d, data, mod_x * d->sizelin, mod_y * d->bpp / 8);
		y++;
	}
}

void	ft_draw_vertical(t_data *d, char *data)
{
	int	y;
	int	mod_x;
	int	mod_y;
	int	max;

	if (d->y1 < d->y2)
	{
		y = d->y1;
		max = d->y2;
	}
	else
	{
		y = d->y2;
		max = d->y1;
	}
	while (y <= max)
	{
		mod_x = d->x1;
		mod_y = (y * d->sizelin + d->x1);
		if (mod_x > 0 && mod_x < 1650 && mod_y > 0 && mod_y < 1000)
			ft_pixel_put(d, data, mod_x, mod_y * d->bpp / 8);
		y++;
	}
}

void	ft_draw_horizontal(t_data *d, char *data)
{
	int	x;
	int	mod_x;
	int	mod_y;
	int	max;

	if (d->x1 < d->x2)
	{
		x = d->x1;
		max = d->x2;
	}
	else
	{
		x = d->x2;
		max = d->x1;
	}
	while (x <= max)
	{
		mod_x = (x * d->bpp / 8 + d->y1);
		mod_y = d->y1;
		if (mod_x > 0 && mod_x < 1650 && mod_y > 0 && mod_y < 1000)
			ft_pixel_put(d, data, mod_x * d->sizelin, mod_y);
		x++;
	}
}

void	ft_draw(t_data *d, char *data, t_mlxp *point1, t_mlxp *point2)
{
	d->x1 = point1->xx;
	d->y1 = point1->yy;
	d->x2 = point2->xx;
	d->y2 = point2->yy;
	if (ABS(point2->xx - point2->yy) >= ABS(point2->yy - point2->xx))
	{
		if (d->x1 != d->x2)
		{
			ft_draw_case_one(d, data);
			ft_draw_case_two(d, data);
		}
		else
			ft_draw_horizontal(d, data);
	}
	else
	{
		if (d->y1 != d->y2)
		{
			ft_draw_case_two(d, data);
			ft_draw_case_one(d, data);
		}
		else
			ft_draw_vertical(d, data);
	}
}
