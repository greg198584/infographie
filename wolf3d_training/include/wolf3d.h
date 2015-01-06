/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:45:13 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/06 17:40:39 by glafitte         ###   ########.fr       */
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

# define ID_WALL		0x778899
# define ID_GROUND		0x8B4513
# define ID_SKY			0x33CCFF

# define ID_KEYP		2
# define ID_KEYR		3

typedef struct		s_vector
{
	float			x;
	float			y;
}					t_vector;

typedef struct		s_img
{
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_labyrinth
{
	int				x;
	int				y;
	char			**patern;
}					t_labyrinth;

typedef struct		s_move
{
	t_vector		*pos;
	int				id_ang;
	float			range_k;
	float			sin_ang[25];
	float			cos_ang[25];
}					t_move;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*sky;
	t_img			*sky_p;
	t_img			*pic;
	t_labyrinth		*lab;
	t_move			*move;
}					t_env;

t_img				*ft_initimg(void *ptr);
t_vector			*ft_init_pos(void);
void				ft_puterror(char *error);
void				ft_conf(t_env *game);
void				ft_move_xy(t_env *par, char up, t_vector **pos);
void				ft_check_collision(t_env *par, t_vector *pos);
float				ft_range(t_env *pr, float x, float y);
void				ft_calc_angles(float *sin_ang, float *cos_ang);
void				ft_init_move(t_env *param, float x, float y);
void				ft_find_pos(t_env *game);
int					ft_expose(t_env *param);
void				ft_sky_ground(t_env *param);
void				ft_display_img(t_env *game);
int					ft_pixel_to_img(t_img *img, unsigned char *color, int i);
int					ft_img_to_pixel(t_env *param, t_img *img, int i, int *k);
void				ft_go(t_env *param);
void				ft_free_vec(t_vector *pos);
int					ft_keyboard(int keycode, t_env *pr);
void				ft_display_wall(t_env *pr);
void				ft_wall(t_env *param, t_vector *pos);

#endif
