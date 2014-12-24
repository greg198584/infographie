/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:05:29 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 18:26:15 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libmlxft/libmlxft.h"

#define WIN_X	800
#define WIN_Y	800

int		expose_hook(t_mlxenv *e)
{
	ft_mlx_draw_circle(e, ft_new_point(WIN_X/2, WIN_Y/2, ft_get_rgb(0,0,255)), 400, 400);
	return (0);
}

int		key_hook(int keycode, t_mlxenv *e)
{
	//printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlxenv *e)
{
	printf("mouse : %d %d %d\n", button, x, y);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlxenv	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fenetre de fouuuuuuuuu !!!!!!");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	//mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
