/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:45:13 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/07 14:03:08 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../lib/libft/libft.h"
# include "../lib/libmlxft/libmlxft.h"
# include <mlx.h>

# define ID_UP			65362
# define ID_DOWN		65364
# define ID_LEFT		65361
# define ID_RIGHT		65363
# define ID_ESCAPE		65307

# define COLOR_WALL		0x778899
# define COLOR_GROUND	0x8B4513
# define COLOR_SKY		0x33CCFF

typedef struct			s_game
{
	t_mlxenv			*env;
	void				*img;
}						t_game;

int						ft_puterror(char *str);
int						ft_expose_hook(t_game *d);

#endif
