/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:58:49 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/17 15:59:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_get_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}
