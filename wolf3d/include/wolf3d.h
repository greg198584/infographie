/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:45:13 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/14 08:33:17 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
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

# define COLOR_WALL		BROWN
# define MAP1			"map/map1"
# define MAP2			"map/map2"

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

typedef struct		s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	t_img			*pic;
	t_labyrinth		*lab;
	t_labyrinth		*lab2;
	t_move			*move;
}					t_game;

int					ft_get_rgb(int r, int g, int b);
void				ft_wall(t_game *param, t_vector *pos);
t_img				*ft_initimg(void *ptr);
int					ft_expose(t_game *e);
t_img				*ft_initimg(void *ptr);
void				ft_wall(t_game *param, t_vector *pos);
void				ft_puterror(char *error);
void				ft_calc_angles(float *sin_ang, float *cos_ang);
float				ft_range(t_game *e, float x, float y);
void				ft_check_collision(t_game *e, t_vector *pos);
void				ft_move_xy(t_game *e, char up, t_vector **pos);
int					ft_pixel_to_img(t_img *img, unsigned char *color, int i);
void				ft_display_img(t_game *e);
void				ft_display_wall(t_game *e);
void				ft_sky_ground(t_game *e);
int					ft_keyboard(int keycode, t_game *e);
void				ft_move_xy(t_game *e, char up, t_vector **pos);
float				ft_range(t_game *e, float x, float y);
void				ft_check_collision(t_game *e, t_vector *pos);
void				ft_free_game(t_game *e);
void				ft_free_vec(t_vector *pos);
t_vector			*ft_init_pos(void);
void				ft_load(t_game *e);
void				ft_init_lab(t_game *e, char **map);
void				ft_init_lab2(t_game *e, char **map);
void				ft_conf_map(t_game *lab, int map);
void				ft_conf_game(int map);

#endif
