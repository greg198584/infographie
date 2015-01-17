/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:09:58 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 17:51:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdlib.h>

int	ft_expose_hook(t_env *e)
{
	ft_putendl("expose hook");
	ft_display_mandelbrot(e);
	return (0);
}
