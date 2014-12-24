/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:05:29 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 17:18:48 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

#define WIN_X	1000
#define WIN_Y	1000

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

int		ft_get_rgb(int r, int g, int b)
{
	return(((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

void	ft_mlx_draw_line(t_env *e, int x1, int y1, int x2, int y2)
{
	float	a;
	float	b;
	int		x;
	int		y;

	a = (float)((y2 - y1)/(x2 - x1));
	b = y1 - a * x1;
	x = x1 - 1;
	while (++x <= x2)
	{
		y = (int)(a * x + b);
		mlx_pixel_put(e->mlx, e->win, x, y, ft_get_rgb(255, 255, 255));
	}
}

int		expose_hook(t_env *e)
{
	ft_mlx_draw_line(e, 65, 228, 319, 234);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	//printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fenetre de fouuuuuuuuu !!!!!!");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	sleep(5);
	return (0);
}
