/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:20:06 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/09 12:34:03 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int	ft_keyboard(int keycode, t_game *e)
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
		ft_free_game(e);
	if (key)
		ft_wall(e, pos);
	ft_free_vec(pos);
	return (0);
}
