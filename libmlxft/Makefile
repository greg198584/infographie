# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 17:37:02 by glafitte          #+#    #+#              #
#    Updated: 2014/11/29 19:01:44 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libmlxft.a
CFLAGS = -Wall -Werror -Wextra -I./ -L/usr/x11/lib -lmlx -lXext -lX11
SRCS = \
		ft_get_rgb.c \
		ft_get_color.c \
		ft_mlx_draw_circle.c \
		ft_new_point.c \
		ft_mlx_draw_line.c \
		ft_mlx_draw_map.c \
		ft_swap_points.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
