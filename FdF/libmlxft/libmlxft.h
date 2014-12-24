/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlxft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:37:15 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 16:15:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLXFT_H
# define LIBMLXFT_H

# define WIN_X				2200
# define WIN_Y				1000

# define MIN(a, b)			((a < b) ? a : b)
# define MAX(a, b)			((a > b) ? a : b)
# define ABS(a)				((a < 0) ? -(a) : a)
# define LINE_C_SRC			0x00
# define LINE_C_DST			0x01
# define LINE_C_MIX			0x02
# define LINE_C_SHD			0x03

# define GET_COLOR_RED		0x10
# define GET_COLOR_BLUE		0x00
# define GET_COLOR_GREEN	0x08

# define RED				ft_get_rgb(255, 0, 0)
# define GREEN				ft_get_rgb(0, 255, 0)
# define BLUE				ft_get_rgb(0, 0, 255)

# define OPT_SWAP_X			0x01
# define OPT_SWAP_Y			0x02
# define OPT_SWAP_C			0x04
# define OPT_SWAP_XY		(OPT_SWAP_X | OPT_SWAP_Y)
# define OPT_SWAP_ALL		(OPT_SWAP_XY | OPT_SWAP_C)

typedef struct				s_mlxp
{
	int						x;
	int						y;
	int						z;
	int						xx;
	int						yy;
	int						rgb;
	struct s_mlxp			*next;
}							t_mlxp;

typedef struct				s_mlxenv
{
	void					*mlx;
	void					*win;
	void					*img;
	int						x_size;
	int						y_size;
	int						square;
}							t_mlxenv;

typedef struct				s_data
{
	int						bpp;
	int						sizelin;
	int						endian;
	float					cte1;
	float					cte2;
	int						x1;
	int						x2;
	int						y1;
	int						y2;
	int						i;
	int						j;
	int						mid_x;
	int						proj_x;
	int						mid_y;
	int						proj_y;
	int						save_line;
}							t_data;

int							ft_get_color(int rgb, int opt);
int							ft_get_rgb(int r, int g, int b);
void						ft_mlx_draw_circle(t_mlxenv *e, t_mlxp p,
												int r, int opt);
t_mlxp						ft_new_point(int x, int y, int rgb);
void						ft_swap_points(t_mlxp *p1, t_mlxp *p2, int opt);
void						ft_mlx_draw_line(t_mlxenv *e, t_mlxp p1, t_mlxp p2);
int							ft_mlx_draw_map(t_mlxenv *e);
void						ft_draw(t_data *d, char *data, t_mlxp *p1,
									t_mlxp *p2);
int							ft_pixel_put(t_data *d, char *data, int x,
											int y);
t_mlxp						*ft_parsing(t_mlxp **list, char **argv, t_data *d);
void						ft_hook(t_mlxenv *ptr, t_mlxp **list);
void						ft_display_map(t_mlxp **p, t_data *d, char *data);

#endif
