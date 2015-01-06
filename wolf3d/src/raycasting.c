/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 22:24:34 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/05 22:33:44 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>
#include <math.h>

void	ft_move_xy(t_env *par, char up, t_vector **pos)
{
	if (up)
	{
		(*pos)->x = par->move->pos->x +
			(0.1 * par->move->cos_ang[par->move->id_ang]);
		(*pos)->y = par->move->pos->y +
			(0.1 * par->move->sin_ang[par->move->id_ang]);
	}
	else
	{
		(*pos)->x = par->move->pos->x -
			(0.1 * par->move->cos_ang[par->move->id_ang]);
		(*pos)->y = par->move->pos->y -
			(0.1 * par->move->sin_ang[par->move->id_ang]);
	}
}

void	ft_check_collision(t_env *par, t_vector *pos)
{
	if (pos->x >= 0 && pos->x <= par->lab->x
			&& pos->y >= 0 && pos->y <= par->lab->y &&
			par->lab->patern[(int)pos->x][(int)pos->y] == '0')
	{
		par->move->pos->x = pos->x;
		par->move->pos->y = pos->y;
	}
}

float	ft_range(t_env *pr, float x, float y)
{
	int		i;
	int		j;
	float	range_k;

	range_k = 1;
	i = x;
	j = y;
	while (pr->lab->patern[i][j] == '0')
	{
		range_k += 0.01;
		i = pr->move->pos->x + (range_k * (x - pr->move->pos->x));
		j = pr->move->pos->y + (range_k * (y - pr->move->pos->y));
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
		rad = M_PI * (i * 15) / 180;
		sin_ang[i] = sin(rad);
		cos_ang[i] = cos(rad);
	}
}
