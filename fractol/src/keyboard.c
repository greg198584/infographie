/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:11:46 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 17:12:33 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdlib.h>

int	ft_key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == ID_ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}
 
