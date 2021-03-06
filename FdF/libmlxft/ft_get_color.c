/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:39:40 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 17:40:51 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_color(int rgb, int opt)
{
	return ((rgb >> opt) & 0xFF);
}
