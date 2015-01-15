/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 23:17:14 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/15 14:28:09 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>
/*
void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	while(map[++i] != NULL)
		free(map[i]);
}
*/
void	ft_free_game(t_game *e)
{
	free(e->mlx);
	free(e->win);
	free(e->img);
	free(e->pic);
	free(e->move->pos);
	free(e->move);
	free(e);
}

void	ft_free_vec(t_vector *pos)
{
	free(pos);
}
