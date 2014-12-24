/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:58:29 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 16:33:43 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "libmlxft/libmlxft.h"
#include <stdlib.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_mlxenv	*e;
	t_mlxp		*list;
	t_data		*data;
	char		*data_mlx;

	if (argc != 2)
		ft_error(ARG_ERROR);
	if ((e = malloc(sizeof(t_mlxenv))) == NULL)
		ft_error(ALLOC_ERROR);
	if ((data = malloc(sizeof(t_data))) == NULL)
		ft_error(ALLOC_ERROR);
	list = NULL;
	ft_parsing(&list, argv, data);
	ft_proj_iso_list(&list, data);
	if ((e->mlx = mlx_init()) == NULL)
		ft_error(END_PROG);
	e->img = mlx_new_image(e->mlx, 1650, 1000);
	data_mlx = mlx_get_data_addr(e->img, &(data->bpp),
								&(data->sizelin), &(data->endian));
	ft_display_map(&list, data, data_mlx);
	e->win = mlx_new_window(e->mlx, 1650, 1000, "FdF");
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_hook(e, &list);
	return (0);
}
