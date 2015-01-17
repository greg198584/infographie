/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 22:39:37 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/09 14:42:48 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		ft_get_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

void	ft_load(t_game *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		ft_puterror("erreur: probleme mlx_init!\n");
	if ((e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "wolf3d")) == NULL)
		ft_puterror("erreur: probleme  mlx_new_window!\n");
	if ((e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT)) == NULL)
		ft_puterror("erreur: probleme mlx_new_image!\n");
}
