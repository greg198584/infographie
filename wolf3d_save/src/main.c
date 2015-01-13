/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:42:00 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/09 12:42:16 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_load_ptr(t_game *ptr)
{
	if ((ptr->mlx = mlx_init()) == NULL)
		ft_puterror("erreur: probleme mlx_init!\n");
	if ((ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "wolf3d")) == NULL)
		ft_puterror("erreur: probleme  mlx_new_window!\n");
	if ((ptr->img = mlx_new_image(ptr->mlx, WIDTH, HEIGHT)) == NULL)
		ft_puterror("erreur: probleme mlx_new_image!\n");
}

int	main(void)
{
	t_game	*game;

	if ((game = malloc(sizeof(*game))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	ft_load_ptr(game);
	if ((game->move = malloc(sizeof(*(game->move)))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	ft_conf_map(game);
	game->pic = ft_initimg(game->img);
	ft_display_img(game);
	mlx_expose_hook(game->win, ft_expose, game);
	mlx_hook(game->win, 2, 3, ft_keyboard, game);
	mlx_loop(game->mlx);
	return (0);
}
