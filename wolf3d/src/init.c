/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:20:11 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/06 12:52:55 by glafitte         ###   ########.fr       */
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

void	ft_init_move(t_env *param, float x, float y)
{
	param->move->pos = ft_init_pos();
	param->move->pos->x = x;
	param->move->pos->y = y;
	param->move->id_ang = 5;
	param->move->range_k = 0;
	ft_calc_angles(param->move->sin_ang, param->move->cos_ang);
}


static void	ft_init_lab(t_env *map, char array[15][15])
{
	int	i;
	int	j;

	if ((map->lab = malloc(sizeof(*(map->lab)))) == NULL)
		ft_puterror("erreur: probleme allocation memoire!\n");
	if ((map->lab->patern = malloc(sizeof(char *) * 15)) == NULL)
		ft_puterror("erreur: probleme allocation memoire!\n");
	i = -1;
	while (++i < 15)
	{
		j = -1;
		if ((map->lab->patern[i] = malloc(sizeof(char) * 15)) == NULL)
			ft_puterror("erreur: probleme allocation memoire!\n");
		while (++j < 15)
			map->lab->patern[i][j] = array[i][j];
	}
	map->lab->x = 15;
	map->lab->y = 15;
	ft_init_move(map, 5.4, 4.5);
}

static void	ft_array(t_env *lab)
{
	char	array[15][15] = {
		{"111111111111111"},
		{"100000000000001"},
		{"100000000000001"},
		{"100000000000001"},
		{"100111111111101"},
		{"100000010000101"},
		{"101100010000101"},
		{"100100010000101"},
		{"100111111001101"},
		{"100100010001001"},
		{"100100010000001"},
		{"100100010000001"},
		{"100100011111001"},
		{"100000000000001"},
		{"111111111111111"}
	};
	ft_init_lab(lab, array);
}

void	ft_conf(t_env *game)
{
	ft_array(game);
//	ft_find_pos(game);
}
