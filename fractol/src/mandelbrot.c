/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:04:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 17:57:50 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

int	ft_display_mandelbrot(t_env *e)
{
	ft_putendl("mandelbrot");
	e->x = -1;
	printf("e->x = [%d] || e->y [%d] || color = [%d]\n", e->x, e->y, e->color);
	while ((e->y = -1) && ++e->x < W)
		while (++e->y < H)
		{
			e->pr = 1.5 * (e->x - W / 2) / (0.5 * e->zoom * W) + e->move_y;
			e->pi = (e->y - H / 2) / (0.5 * e->zoom * H) + e->move_y;
			e->new_re = e->new_im = e->old_re = e->old_i = 0;
			e->i = -1;
			while (++e->i < e->max_iter)
			{
				e->old_re = e->new_re;
				e->old_i = e->new_im;
				e->new_re = e->old_re * e->old_re - e->old_i * e->old_i + e->pr;
				e->new_im = 2 * e->old_re * e->old_i + e->pi;
				if ((e->new_re * e->new_re + e->new_im * e->new_im) > 4)
					break ;
			}
			e->color = ft_get_rgb(255, 255 * (e->i < e->max_iter), e->i % 256);
			mlx_pixel_put(e->mlx, e->win, e->x, e->y, e->color);
			ft_putstr("---> ");
			printf("e->x = [%d] || e->y [%d] || color = [%d]\n", e->x, e->y, e->color);
		}
	ft_putendl("Fin mandelbrot");
	return (0);
}

int	ft_config_mandelbrot(t_env *e)
{
	ft_putendl("config mandelbrot");
	e->zoom = -1;
	e->move_x = -0.5;
	e->move_y = 0;
	e->max_iter = 300;
	return (0);
}
