# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/03 11:11:20 by glafitte          #+#    #+#              #
#    Updated: 2015/01/03 11:16:35 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fractol
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = libft -lft
LIBMLX = /usr/X11/lib
MLXFLAGS = -lXext -lmlx -lX11
SRCS =	main.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	gcc $(CFLAGS) -c $(SRCS)
	gcc $(OBJ) -o $(NAME) -L $(LIBFT) -L $(LIBMLX) $(MLXFLAGS)

clean :
	@make -C $(LIBFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
