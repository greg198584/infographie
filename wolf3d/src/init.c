/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:44:07 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/16 11:07:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

static void	ft_load_mlx(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		ft_puterror("erreur: probleme mlx_init!\n");
	if ((e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "wolf3d")) == NULL)
		ft_puterror("erreur: probleme  mlx_new_window!\n");
}

void		ft_init_game(int map)
{
	t_env	*e;
	//int		h;
	//int		w;

	if ((e = malloc(sizeof(*e))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	ft_load_mlx(e);
	ft_conf_map(e, map);
	mlx_key_hook(e->win, key_hook, &e);
	mlx_expose_hook(e->win, expose_hook, &e);
	mlx_loop(e->mlx);

}
