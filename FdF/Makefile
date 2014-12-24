# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/14 08:37:45 by glafitte          #+#    #+#              #
#    Updated: 2014/12/01 13:59:31 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fdf
CFLAGS = -Wall -Werror -Wextra -O3 -g
LIBMLXFT = libmlxft -lmlxft
LIBFT = libft -lft
LIBMLX = /usr/X11/lib
MLXFLAGS = -lXext -lmlx -lX11
SRCS =  \
		error.c \
		parsing.c \
		word.c \
		main.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBMLXFT) fclean
	@make -C $(LIBMLXFT)
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	gcc $(CFLAGS) -c $(SRCS)
	gcc $(OBJ) -o $(NAME) -L $(LIBMLXFT) -L $(LIBFT) -L $(LIBMLX) $(MLXFLAGS)

clean :
	@make -C $(LIBMLXFT) clean
	@make -C $(LIBFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBMLXFT) fclean
	@make -C $(LIBFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
