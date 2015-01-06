/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:42:00 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/05 23:23:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_load_ptr(t_env *ptr)
{
	int	w;
	int	h;

	if ((ptr->mlx = mlx_init()) == NULL)
		ft_puterror("error: problem with mlx_init!\n");
	if ((ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT, "wolf3d")) == NULL)
		ft_puterror("error: problem with mlx_new_window!\n");
	if ((ptr->img = mlx_new_image(ptr->mlx, WIDTH, HEIGHT)) == NULL)
		ft_puterror("error: problem with mlx_new_image!\n");
	if ((ptr->sky = mlx_xpm_file_to_image(ptr->mlx, "./img/img_sky.xpm", &w, &h))
			== NULL || w != 800 || h != 300)
		ft_puterror("error: problem with mlx_xpm_file_to_image!\n");
}

int	main(void)
{
	t_env	*game; //ptr

	if ((game = malloc(sizeof(*game))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	ft_load_ptr(game);
	if ((game->move = malloc(sizeof(*(game->move)))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	ft_conf(game);
	game->pic = ft_initimg(game->img);
	game->sky_p = ft_initimg(game->sky);
	ft_display_img(game);
	(void)mlx_expose_hook(game->win, ft_expose, game);
	(void)mlx_hook(game->win, ID_KEYP, ID_KEYR, ft_keyboard, game);
	(void)mlx_loop(game->mlx);
	return (0);
}
