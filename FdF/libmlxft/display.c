/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:05:17 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 16:14:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "libmlxft.h"
#include "../libft/libft.h"

int		ft_pixel_put(t_data *d, char *data, int x, int y)
{
	if (d->bpp == 0 || d->sizelin == 0)
		ft_error(PIX_AND_SIZE_ERROR);
	data[(x + y)] = 0xFF;
	data[(x + y) + 1] = 0xFF;
	data[(x + y) + 2] = 0xFF;
	data[(x + y) + 3] = 0;
	return (0);
}

void	ft_display_map(t_mlxp **p, t_data *d, char *data)
{
	t_mlxp	*point1;
	t_mlxp	*point2;

	point1 = *p;
	while (point1 != NULL)
	{
		point2 = *p;
		while (point2 != NULL)
		{
			if (point1->x == point2->x - 1 && point1->y == point2->y)
				ft_draw(d, data, point1, point2);
			if (point1->y == point2->y - 1 && point1->x == point2->x)
				ft_draw(d, data, point1, point2);
			point2 = point2->next;
		}
		point1 = point1->next;
	}
}
