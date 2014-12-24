# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/14 08:37:45 by glafitte          #+#    #+#              #
#    Updated: 2014/11/27 18:19:01 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = mlx_ft_main
CFLAGS = -Wall -Werror -Wextra -O3 -g
LIBMLXFT = ../libmlxft
LIBMLX = /usr/X11/lib
MLXFLAGS = -lXext -lmlx -lX11
SRCS = main.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBMLXFT) fclean
	@make -C $(LIBMLXFT)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(OBJ) -o $(NAME) -L $(LIBMLXFT) -lmlxft -L $(LIBMLX) $(MLXFLAGS)
clean :
	@make -C $(LIBMLXFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBMLXFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
