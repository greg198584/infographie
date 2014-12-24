/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:26:43 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 12:17:10 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
