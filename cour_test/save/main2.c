/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:05:29 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 12:52:36 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>

int	ft_get_rgb(int r, int g, int b)
{
	return(((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}
int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "42");
	y = 0;
	while (y < 256)
	{
		x = 0;
		while (x < 255)
		{
			mlx_pixel_put(mlx, win, x + 50, y + 50, ft_get_rgb(255, x, y));
			x++;
		}
		y++;
	}
	sleep(10);
	return (0);
}

