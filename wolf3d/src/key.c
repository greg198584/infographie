/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:20:06 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/05 23:18:45 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int	ft_keyboard(int keycode, t_env *pr)
{
	t_vector	*pos;
	char		key;

	pos = ft_init_pos();
	key = 1;
	if (keycode == ID_UP || keycode == 'w')
		ft_move_xy(pr, 1, &pos);
	else if (keycode == ID_DOWN || keycode == 's')
		ft_move_xy(pr, 0, &pos);
	else if (keycode == ID_LEFT || keycode == 'a')
		pr->move->id_ang = pr->move->id_ang == 24 ? 1 : pr->move->id_ang + 1;
	else if (keycode == ID_RIGHT || keycode == 'd')
		pr->move->id_ang = pr->move->id_ang == 0 ? 23 : pr->move->id_ang - 1;
	else
		key = 0;
	if (keycode == ID_ESCAPE)
		ft_go(pr);
	//if (key)
	//	my_wall(pr, pos);
	ft_free_vec(pos);
	return (0);
}
