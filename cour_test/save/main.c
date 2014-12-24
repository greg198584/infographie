/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:05:29 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 14:35:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

int		ft_get_rgb(int r, int g, int b)
{
	return(((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
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
	draw(e->mlx, e->win);
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
	e.win = mlx_new_window(e.mlx, 420, 420, "fenetre de fouuuuuuuuu !!!!!!");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
