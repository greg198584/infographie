/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 23:17:14 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/14 08:37:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_free_game(t_game *e)
{
	free(e->mlx);
	free(e->win);
	free(e->img);
	free(e->pic);
	free(e->move->pos);
	free(e->move);
	free(e->lab);
	free(e);
}

void	ft_free_vec(t_vector *pos)
{
	free(pos);
}
