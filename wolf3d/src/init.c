/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:20:11 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/14 08:42:02 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <get_next_line.h>
#include <stdlib.h>
#include <unistd.h>

t_vector	*ft_init_pos(void)
{
	t_vector	*pos;

	if ((pos = malloc(sizeof(*pos))) == NULL)
		ft_puterror("erreur: probleme d'allocation memoire!\n");
	pos->x = 0;
	pos->y = 0;
	return (pos);
}

static void	ft_init_move(t_game *e, float x, float y)
{
	e->move->pos = ft_init_pos();
	e->move->pos->x = x;
	e->move->pos->y = y;
	e->move->id_ang = 5;
	e->move->range_k = 0;
	ft_calc_angles(e->move->sin_ang, e->move->cos_ang);
}

void		ft_init_lab(t_game *e, char **map)
{
	int	i;
	int	j;

	ft_putendl("init_lab");
	if ((e->lab = malloc(sizeof(*(e->lab)))) == NULL)
		ft_puterror("erreur: probleme allocation memoire!\n");
	if ((e->lab->patern = malloc(sizeof(char *) * 20)) == NULL)
		ft_puterror("erreur: probleme allocation memoire!\n");
	i = -1;
	while (++i < 20)
	{
		j = -1;
		if ((e->lab->patern[i] = malloc(sizeof(char) * 20)) == NULL)
			ft_putendl("erreur: probleme allocation memoire!\n");
		while (++j < 20)
		{
			e->lab->patern[i][j] = map[i][j];
		}
	}
	e->lab->x = 20;
	e->lab->y = 20;
	ft_init_move(e, 15, 2);
}
