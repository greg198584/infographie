/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:31:04 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 17:48:35 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdlib.h>

void	ft_puterror(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	ft_usage(void)
{
	ft_putendl("Usage: ./fractol [nom fractal]");
	ft_putendl("ex: ./fractol mandelbrot");
	exit(EXIT_FAILURE);
}
