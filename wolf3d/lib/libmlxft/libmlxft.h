/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlxft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:37:15 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/07 13:40:15 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLXFT_H
# define LIBMLXFT_H

#include <mlx.h>

# define X					0
# define Y					1
# define WIN_X				1800
# define WIN_Y				1200

# define MIN(a, b)			((a < b) ? a : b)
# define MAX(a, b)			((a > b) ? a : b)

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

# define ABS(a)				((a < 0) ? -(a) : a)

typedef struct				s_mlxp
{
	int						x;
	int						y;
	int						z;
	int						rgb;
}							t_mlxp;

typedef struct				s_mlxenv
{
	void					*mlx;
	void					*win;
	int						x_size;
	int						y_size;
	int						square;
}							t_mlxenv;

int							ft_get_color(int rgb, int opt);
int							ft_get_rgb(int r, int g, int b);
void						ft_mlx_draw_circle(t_mlxenv *e, t_mlxp p,
												int r, int opt);
t_mlxp						ft_new_point(int x, int y, int z, int rgb);
void						ft_swap_points(t_mlxp *p1, t_mlxp *p2, int opt);
void						ft_mlx_draw_line(t_mlxenv *e, t_mlxp p, t_mlxp p2);

#endif
