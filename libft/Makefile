# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 14:28:55 by rukoltso          #+#    #+#              #
#    Updated: 2023/12/04 16:01:06 by rukoltso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_split.c		\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_strmapi.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		get_next_line.c		\
		get_next_line_utils.c	\
		ft_word_counter.c	\
		ft_printf.c				\
		ft_printf_hex.c			\
		ft_printf_ptr.c			\
		ft_printf_u_nbr.c		\
		ft_printf_utilities.c	\
		ft_itoa.c				\

NAME=libft.a

OBJECTS=*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f *.so

re: fclean all
