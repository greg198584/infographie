/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 22:58:52 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/09 11:58:58 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_expose(t_game *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

t_img	*ft_initimg(void *ptr)
{
	t_img	*img;

	if ((img = malloc(sizeof(*img))) == NULL)
		ft_puterror("error: problem to malloc!\n");
	img->data = mlx_get_data_addr(ptr, &(img->bpp), &(img->sizeline),
			&(img->endian));
	return (img);
}

void	ft_wall(t_game *e, t_vector *pos)
{
	ft_check_collision(e, pos);
	ft_sky_ground(e);
	ft_display_wall(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_sky_ground(t_game *e)
{
	int				i;
	unsigned int	color;
	unsigned char	*ground;

	color = mlx_get_color_value(e->mlx, COLOR_GROUND);
	ground = (unsigned char *)&color;
	i = 0;
	while (i < HEIGHT * e->pic->sizeline)
		i = ft_pixel_to_img(e->pic, ground, i);
}
