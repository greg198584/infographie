/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:56:52 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 17:48:31 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>

# define ID_UP		65362
# define ID_DOWN	65364
# define ID_LEFT	65361
# define ID_RIGHT	65363
# define ID_ESCAPE	65307

# define W			1200
# define H			1000

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	double			pr;
	double			pi;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_i;
	double			zoom;
	double			move_x;
	double			move_y;
	int				max_iter;
	int				color;
	int				x;
	int				y;
	int				i;
}					t_env;

int					ft_get_rgb(int r, int g, int b);
void				ft_puterror(char *error);
int					ft_config_mandelbrot(t_env *e);
int					ft_key_hook(int keycode, t_env *e);
int					ft_expose_hook(t_env *e);
int					ft_expose_hook(t_env *e);
int					ft_display_mandelbrot(t_env *e);
void				ft_usage(void);

#endif
