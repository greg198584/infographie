/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:42:00 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/07 14:14:56 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_key_hook(int keycode , t_game *e)
{
	(void)e;

	if (keycode == ID_ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_game	data;
	int		w;
	int		h;
	
	data.env = malloc(sizeof(t_mlxenv));
	data.env->mlx = mlx_init();
	if ((data.img = mlx_xpm_file_to_image(data.env->mlx, "./img/beaucielbleu.xpm",
			&w, &h)) == NULL || w != 1800 || h != 600)
		ft_puterror("erreur: ft_expose_hook --> chargement image\n");
	data.env->win = mlx_new_window(data.env->mlx, WIN_X, WIN_Y, "Wolf3d");
	mlx_expose_hook(data.env->win, ft_expose_hook, &data);
	mlx_key_hook(data.env->win, ft_key_hook, &data);
	mlx_loop(data.env->mlx);
	return (0);
}
