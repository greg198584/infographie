/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:25:41 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 15:21:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "libmlxft.h"
#include <mlx.h>

int		ft_gere_key(int keycode, t_mlxp *elem)
{
	if (keycode == 65307)
		ft_error(END_PROG);
	if (keycode == 65453)
		elem->z--;
	if (keycode == 65451)
		elem->z++;
	return (0);
}

int		ft_gere_expose(t_mlxenv *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (0);
}

void	ft_hook(t_mlxenv *ptr, t_mlxp **list)
{
	mlx_key_hook(ptr->win, ft_gere_key, list);
	mlx_expose_hook(ptr->win, ft_gere_expose, ptr);
	mlx_loop(ptr->mlx);
}
