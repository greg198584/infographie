/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 22:24:34 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/12 14:50:13 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>
#include <math.h>

void	ft_move_xy(t_game *e, char up, t_vector **pos)
{
	if (up)
	{
		(*pos)->x = e->move->pos->x +
			(0.1 * e->move->cos_ang[e->move->id_ang]);
		(*pos)->y = e->move->pos->y +
			(0.1 * e->move->sin_ang[e->move->id_ang]);
	}
	else
	{
		(*pos)->x = e->move->pos->x -
			(0.1 * e->move->cos_ang[e->move->id_ang]);
		(*pos)->y = e->move->pos->y -
			(0.1 * e->move->sin_ang[e->move->id_ang]);
	}
}

void	ft_check_collision(t_game *e, t_vector *pos)
{
	if (pos->x >= 0 && pos->x <= e->lab->x
			&& pos->y >= 0 && pos->y <= e->lab->y &&
			e->lab->patern[(int)pos->x][(int)pos->y] == '0')
	{
		e->move->pos->x = pos->x;
		e->move->pos->y = pos->y;
	}
}

float	ft_range(t_game *e, float x, float y)
{
	int		i;
	int		j;
	float	range_k;

	range_k = 1;
	i = x;
	j = y;
	while (e->lab->patern[i][j] == '0')
	{
		range_k += 0.01;
		i = e->move->pos->x + (range_k * (x - e->move->pos->x));
		j = e->move->pos->y + (range_k * (y - e->move->pos->y));
	}
	return (range_k);
}

void	ft_calc_angles(float *sin_ang, float *cos_ang)
{
	int		i;
	float	rad;

	i = -1;
	while (++i < 25)
	{
		rad = M_PI * (i * 15) / 90;
		sin_ang[i] = sin(rad);
		cos_ang[i] = cos(rad);
	}
}
