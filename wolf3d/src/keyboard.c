/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:44:15 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/16 11:09:03 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == ID_ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}
