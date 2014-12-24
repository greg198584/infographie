/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:05:29 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 16:13:44 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

#define WIN_X	1400
#define WIN_Y	1400

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

void	ft_mlx_draw_line(int x1, int y1, int x2, int y2);

int		ft_get_rgb(int r, int g, int b)
{
	return(((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

void	ft_mlx_draw_circle(t_env *e, int xc, int yc, int r, int opt)
{
	int		x;
	int		y;
	int		d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		mlx_pixel_put(e->mlx, e->win, xc + x, yc + y, ft_get_rgb(255, 0, 0));
		mlx_pixel_put(e->mlx, e->win, xc + y, yc + x, ft_get_rgb(249, 66, 158));
		mlx_pixel_put(e->mlx, e->win, xc - x, yc + y, ft_get_rgb(255, 255, 255));
		mlx_pixel_put(e->mlx, e->win, xc - y, yc + x, ft_get_rgb(249, 66, 158));
		mlx_pixel_put(e->mlx, e->win, xc + x, yc - y, ft_get_rgb(255, 255, 255));
		mlx_pixel_put(e->mlx, e->win, xc + y, yc - x, ft_get_rgb(249, 255, 156));
		mlx_pixel_put(e->mlx, e->win, xc - x, yc - y, ft_get_rgb(0, 0, 255));
		mlx_pixel_put(e->mlx, e->win, xc - y, yc - x, ft_get_rgb(0, 255, 0));
		if (d >= (2 * x))
			d = d - (2 * x++) -1;
		else if (d < (2 * (r - y)))
			d = d + (2 * y--) - 1;
		else
			d = d + (2 * (y-- - x++ -1));
		usleep(100);
	}
	if (r-- > 0 && opt-- > 0)
		ft_mlx_draw_circle(e, xc, yc, r, opt);
}

void	draw(void	*mlx, void	*win)
{
	int		x;
	int		y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, ft_get_rgb(255, x, y));
			x++;
		}
		y++;
	}
	return ;
}

int		expose_hook(t_env *e)
{
	ft_mlx_draw_circle(e, WIN_X/2, WIN_Y/2, 400, 400);
	//draw(e->mlx, e->win);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	//printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d %d %d\n", button, x, y);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fenetre de fouuuuuuuuu !!!!!!");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	//mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	//ft_mlx_draw_circle(&e, WIN_X/2, WIN_Y/2, 100, 90);
	sleep(5);
	return (0);
}
