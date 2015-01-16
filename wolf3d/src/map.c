/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:44:21 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/16 10:14:31 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <get_next_line.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void	ft_init_map(t_env *e, int fd)
{
	char	*line;
	int		res;
	int		i;

	i = 0;
	if ((e->map = (char **)malloc(sizeof(char *) * 21)) == NULL)
		ft_puterror("erreur: probleme allocation memoire!\n");
	while ((res = get_next_line(fd, &line)) > 0)
		e->map[i++] = line;
	close(fd);
	i = 0;
	while (e->map[i++] != '\0')
		ft_putendl(e->map[i]);
}

void		ft_conf_map(t_env *e, int map)
{
	int		fd;
	char	*filename;

	if (map == 1)
		filename = MAP1;
	else
		filename = MAP2;
	fd = open(filename, O_RDONLY);
	ft_init_map(e, fd);
}
