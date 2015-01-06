/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 22:58:52 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/05 23:22:11 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_expose(t_env *param)
{
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
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

void	ft_sky_ground(t_env *param)
{
	int				i;
	int				k;
	unsigned int	color;
	unsigned char	*ground;

	color = mlx_get_color_value(param->mlx, ID_GROUND);
	ground = (unsigned char *)&color;
	i = 0;
	k = 0;
	while (i < (param->pic->sizeline * (HEIGHT / 2)))
		i = ft_img_to_pixel(param, param->sky_p, i, &k);
	while (i < HEIGHT * param->pic->sizeline)
		i = ft_pixel_to_img(param->pic, ground, i);
}
