/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:06:27 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/01 16:30:18 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libmlxft/libmlxft.h"

# define ARG_ERROR			"Erreur veuillez entrer un seul argument"
# define ALLOC_ERROR		"Erreur allocation"
# define END_PROG			"Fin programme"
# define PIX_AND_SIZE_ERROR	"bit par pixel ou taille null"
# define MAP_ERROR			"Erreur map : taille non conforme."

t_mlxp		*ft_parsing(t_mlxp **list, char **argv, t_data *d);
void		ft_error(char *str);
t_mlxp		*ft_rev_list(t_mlxp **list);
int			ft_word_count(char *str);
void		ft_proj_iso_list(t_mlxp **list, t_data *d);

#endif
