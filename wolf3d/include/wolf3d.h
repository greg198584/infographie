/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:52:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/16 11:07:12 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../lib/libft/libft.h"
# include <mlx.h>

# define ID_UP			65362
# define ID_DOWN		65364
# define ID_LEFT		65361
# define ID_RIGHT		65363
# define ID_ESCAPE		65307

# define WIDTH			1200
# define HEIGHT			1000

# define RED			ft_get_rgb(255, 0, 0)
# define GREY			ft_get_rgb(128, 128, 128)
# define GREEN			ft_get_rgb(46, 139, 87)
# define BROWN			ft_get_rgb(139, 69, 9)
# define BLUE			ft_get_rgb(0, 255, 255)

# define MAP1			"map/map1"
# define MAP2			"map/map2"

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	char				**map;
}						t_env;

void					ft_conf_map(t_env *e, int map);
void					ft_puterror(char *error);
void					ft_conf_map(t_env *e, int map);
void					ft_init_game(int map);
int						key_hook(int keycode, t_env *e);
int						expose_hook(t_env *e);

#endif
