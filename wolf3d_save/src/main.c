/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:42:00 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 10:29:28 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_conf_game(int map)
{
	t_game	*game;
	int		w;
	int		h;

	if ((game = malloc(sizeof(*game))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	ft_load(game);
	if ((game->move = malloc(sizeof(*(game->move)))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	if ((game->sky = mlx_xpm_file_to_image(game->mlx, "img/sky.xpm", &w, &h))
			== NULL || w != 1200 || h != 500)
		ft_puterror("erreur: mlx_xpm_file_to_image : sky !\n");
	ft_conf_map(game, map);
	game->pic = ft_initimg(game->img);
	game->sky_p = ft_initimg(game->sky);
	ft_display_img(game);
	mlx_expose_hook(game->win, ft_expose, game);
	mlx_hook(game->win, 2, 3, ft_keyboard, game);
	mlx_loop(game->mlx);
}

int		main(void)
{
	ft_conf_game(1);
	return (0);
}
