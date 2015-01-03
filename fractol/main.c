/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:12:26 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/03 11:15:33 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <mlx.h>

int ft_get_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}

int	main(int argc, char **argv, char **env)
{
	void	*win;
	void	*mlx;


	int h;
	int w;

	w = 1200;
	h = 800;
	mlx = mlx_init();
	win = mlx_new_window(mlx, w, h, "Mandelbrot Set");

	double pr, pi;
	double newRe, newIm, oldRe, oldIm;
	double zoom = 1, moveX = -0.5, moveY = 0;
	int maxIterations = 300;
	int color;
	int x = -1;
	int y;
	int i;
	while (++x < w && (y = -1))
		while (++y < h)
		{
			pr = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
			pi = (y - h / 2) / (0.5 * zoom * h) + moveY;
			newRe = newIm = oldRe = oldIm = 0;
			i = -1;
			while (++i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break ;
			}
			color = ft_get_rgb(255, 255 * (i < maxIterations), i % 256);
			mlx_pixel_put(mlx, win, x, y, color);
		}


(void)mlx;
	(void)win;

	mlx_loop(mlx);
	(void)argc;
	(void)argv;
	(void)env;
	return (0);
}
