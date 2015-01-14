/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:21:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/14 08:37:03 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <get_next_line.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void	ft_init_map(t_game *e, int fd)
{
	char	*line;
	char	**map;
	int		res;
	int		i;

	i = 0;
	map = malloc(sizeof(char) * 128);
	while ((res = get_next_line(fd, &line)) > 0)
		map[i++] = line;
	close(fd);
	ft_init_lab(e, map);
}

void		ft_conf_map(t_game *lab, int map)
{
	int		fd;
	char 	*filename;

	if (map == 1)
		filename = MAP1;
	else
		filename = MAP2;
	fd = open(filename, O_RDONLY);
	ft_init_map(lab, fd);
}
