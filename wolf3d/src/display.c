/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:20:19 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/05 23:11:38 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <wolf3d.h>

void	ft_display_img(t_env *game)
{
	ft_sky_ground(game);
	//ft_display_wall(game);
}

int	ft_pixel_to_img(t_img *img, unsigned char *color, int i)
{
	int	j;

	if (!img->endian)
	{
		j = -1;
		while (++j < img->bpp / 8)
		{
			img->data[i] = color[j];
			++i;
		}
	}
	else
	{
		j = img->bpp / 8;
		while (--j >= 0)
		{
			img->data[i] = color[j];
			++i;
		}
	}
	return (i);
}

int	ft_img_to_pixel(t_env *param, t_img *img, int i, int *k)
{
	int	j;

	if (!param->pic->endian)
	{
		j = -1;
		while (++j <= param->pic->bpp / 8)
		{
			param->pic->data[i] = img->data[*k];
			++(*k);
			++i;
		}
	}
	else
	{
		j = param->pic->bpp / 8;
		while (--j >= 0)
		{
			param->pic->data[i] = img->data[*k + j];
			++i;
		}
		(*k) = (*k) + 4;
	}
	return (i);
}
