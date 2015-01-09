/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:20:19 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/09 12:34:45 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <wolf3d.h>

void	ft_display_img(t_game *e)
{
	ft_sky_ground(e);
	ft_display_wall(e);
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
