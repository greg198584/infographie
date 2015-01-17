/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:20:19 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/15 16:30:53 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wolf3d.h>

void	ft_display_img(t_game *e)
{
	ft_sky_ground(e);
	ft_display_wall(e);
}

int		ft_pixel_to_img(t_img *img, unsigned char *color, int i)
{
	int	j;

	if (!img->endian)
	{
		j = -1;
		while (++j < img->bpp / 10)
		{
			img->data[i] = color[j];
			++i;
		}
	}
	else
	{
		j = img->bpp / 10;
		while (--j >= 0)
		{
			img->data[i] = color[j];
			++i;
		}
	}
	return (i);
}

int		ft_img_to_pixel(t_game *e, t_img *img, int i, int *k)
{
	int	j;

	if (!e->pic->endian)
	{
		j = -1;
		while (++j <= e->pic->bpp / 8)
		{
			e->pic->data[i] = img->data[*k];
			++(*k);
			++i;
		}
	}
	else
	{
		j = e->pic->bpp / 8;
		while (--j >= 0)
		{
			e->pic->data[i] = img->data[*k + j];
			++i;
		}
		(*k) = (*k) + 4;
	}
	return (i);
}
