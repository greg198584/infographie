/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 18:38:09 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/29 18:45:58 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"

void	ft_swap_points(t_mlxp *p1, t_mlxp *p2, int opt)
{
	if (opt & OPT_SWAP_X)
	{
		p1->x = p1->x ^ p2->x;
		p2->x = p1->x ^ p2->x;
		p1->x = p1->x ^ p2->x;
	}
	if (opt & OPT_SWAP_Y)
	{
		p1->y = p1->y ^ p2->y;
		p2->y = p1->y ^ p2->y;
		p1->y = p1->y ^ p2->y;
	}
	if (opt & OPT_SWAP_C)
	{
		p1->rgb = p1->rgb ^ p2->rgb;
		p2->rgb = p1->rgb ^ p2->rgb;
		p1->rgb = p1->rgb ^ p2->rgb;
	}
}
