# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/17 15:55:15 by glafitte          #+#    #+#              #
#    Updated: 2015/01/17 17:47:00 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fractol
CFLAGS = -Wall -Wextra -Werror -g -I include/
LIBX = -L /usr/X11/lib -lmlx -lX11 -lXext
LIBFT =  libft
CC = gcc
SRCS =	src/main.c \
		src/error.c \
		src/mandelbrot.c \
		src/display.c \
		src/keyboard.c \
		src/color.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT) re
	$(CC) $(OBJ) -o $(NAME) -L $(LIBFT) -lft $(LIBX)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) -I include/ $< -c $(SRCS)

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
