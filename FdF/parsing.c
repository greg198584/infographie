/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:34:51 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 16:29:17 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft/libmlxft.h"
#include "libft/libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_mlxp			*ft_rev_list(t_mlxp **list)
{
	t_mlxp	*cur_elem;
	t_mlxp	*prev_elem;
	t_mlxp	*next_elem;

	cur_elem = *list;
	prev_elem = NULL;
	next_elem = NULL;
	while (cur_elem != NULL)
	{
		*list = cur_elem;
		prev_elem = cur_elem->next;
		cur_elem->next = next_elem;
		next_elem = cur_elem;
		cur_elem = prev_elem;
	}
	return (prev_elem);
}

void			ft_proj_iso_list(t_mlxp **list, t_data *d)
{
	t_mlxp	*elem;

	d->cte1 = 0.7;
	d->cte2 = 0.7;
	d->proj_x = 50;
	d->proj_y = 50;
	d->mid_x = 1680 / 2 - d->save_line;
	d->mid_y = 1000 / 2 - d->j;
	elem = *list;
	while (elem != NULL)
	{
		elem->xx = ((d->cte1 * (elem->x * d->proj_x)) -
					(d->cte2 * (elem->y * d->proj_y)) + d->mid_x);
		elem->yy = ((elem->z * (-5)) + (d->cte1 / 2) * (elem->x * (35)) +
					(d->cte2 / 2) * (elem->y * d->proj_y) + d->mid_y);
		elem = elem->next;
	}
}

static void		ft_fill_list(t_mlxp **list, char **tab, int i, int j)
{
	t_mlxp	*elem;

	if ((elem = malloc(sizeof(t_mlxp))) == NULL)
		exit (0);
	elem->x = i;
	elem->y = j;
	elem->z = ft_atoi(tab[i]);
	elem->next = *list;
	*list = elem;
}

t_mlxp			*ft_parsing(t_mlxp **list, char **argv, t_data *d)
{
	char	**tab;
	char	*s;
	int		fd;

	d->j = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(0);
	while (get_next_line(fd, &s) > 0)
	{
		d->i = -1;
		tab = ft_strsplit(s, ' ');
		if (d->j == 0)
			d->save_line = ft_word_count(s) + 1;
		while (tab[++d->i])
			ft_fill_list(list, tab, d->i, d->j);
		free(s);
		d->j++;
	}
	close(fd);
	return (ft_rev_list(list));
}
