# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 12:29:48 by rukoltso          #+#    #+#              #
#    Updated: 2023/12/01 16:33:34 by rukoltso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s

NAME = fdf
FLAGS = -Werror -Wextra -Wall -g
LIBFT = -Llibft -lft
MINILIBX = -Lminilibx-linux -lmlx
X11LIB = -L/usr/lib -lXext -lX11 -lm -lz
SRC=src/*.c

$(NAME): $(SRC)
	@echo "Compiling $@"
	make -C libft/
	make -C minilibx-linux/
	cc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MINILIBX) $(X11LIB)

all: $(NAME)

clean:
	make -s -C libft/ fclean
	make -s -C minilibx-linux/ clean

fclean: clean
	@echo "Cleaning $(NAME)"
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re