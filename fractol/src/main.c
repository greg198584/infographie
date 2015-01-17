/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:12:26 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 17:47:42 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdlib.h>

int	ft_init_mlx(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		ft_puterror("erreur: mlx_init()");
	e->win = mlx_new_window(e->mlx, W, H, "Fractol");
	mlx_key_hook(e->win, ft_key_hook, &e);
	mlx_expose_hook(e->win, ft_expose_hook, &e);
	mlx_loop(e->mlx);
	return (0);
}

int	main(void)
{
	t_env	*e;

	if ((e = malloc(sizeof(*e))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire, main.c !");
	ft_config_mandelbrot(e);
	ft_init_mlx(e);
	return (0);
}
