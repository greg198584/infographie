/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 23:17:14 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/05 23:18:18 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

void	ft_go(t_env *param)
{
	free(param->mlx);
	free(param->sky);
	free(param->win);
	free(param->img);
	free(param->sky_p);
	free(param->pic);
	free(param->move->pos);
	free(param->move);
	free(param->lab);
	free(param);
	exit(EXIT_SUCCESS);
}

void	ft_free_vec(t_vector *pos)
{
	free(pos);
}
