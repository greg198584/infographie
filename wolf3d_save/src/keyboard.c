/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:47:32 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/15 16:55:49 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

static void	ft_change_map(t_game *e, t_vector *pos)
{
	ft_free_game(e);
	ft_free_vec(pos);
	ft_conf_game(2);
	ft_putendl("Chargement nouvelle map");
}

static void	ft_exit_game(t_game *e)
{
	ft_free_game(e);
	exit(EXIT_SUCCESS);
}

int			ft_keyboard(int keycode, t_game *e)
{
	t_vector	*pos;
	char		key;

	pos = ft_init_pos();
	key = 1;
	if (keycode == ID_UP)
		ft_move_xy(e, 1, &pos);
	else if (keycode == ID_DOWN)
		ft_move_xy(e, 0, &pos);
	else if (keycode == ID_LEFT)
		e->move->id_ang = e->move->id_ang == 24 ? 1 : e->move->id_ang + 1;
	else if (keycode == ID_RIGHT)
		e->move->id_ang = e->move->id_ang == 0 ? 23 : e->move->id_ang - 1;
	else
		key = 0;
	if (keycode == ID_ESCAPE)
		ft_exit_game(e);
	if (key)
		ft_wall(e, pos);
	if ((pos->x > 1 && pos->x < 2) && pos->y > 18)
		ft_change_map(e, pos);
	ft_free_vec(pos);
	return (0);
}
