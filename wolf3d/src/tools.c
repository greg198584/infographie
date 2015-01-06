/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 22:39:37 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/05 23:24:41 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_find_pos(t_env *game)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (++i < game->lab->x && !found)
	{
		j = -1;
		while (++j < game->lab->y && !found)
		{
			if (game->lab->patern[i][j] == '2')
			{
				game->lab->patern[i][j] = '0';
				found = 1;
			}
		}
	}
	if (!found)
		ft_puterror("erreur: impossible de trouver le joueur!\n");
	ft_init_move(game, i + 0.5, j + 0.5);
}
