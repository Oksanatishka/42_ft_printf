# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obibik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 12:32:33 by obibik            #+#    #+#              #
#    Updated: 2018/10/16 12:32:36 by obibik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

LIB = libft.a

SOURCES = convert.c \
		  ft_handle_addr.c \
		  ft_handle_char.c \
		  ft_wstr_help.c \
		  ft_handle_int.c \
		  ft_handle_str.c \
		  ft_handle_wstr.c \
		  ft_printf.c \
		  convert_spec.c \
		  ft_handle_binary.c \
		  ft_handle_hex.c \
		  ft_handle_octal.c \
		  ft_handle_uint.c \
		  ft_parse_specifier.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(FLAGS) -c $(SOURCES) -I $(LIBFT)
	ar rc $(NAME) $(OBJS) $(LIBFT)/*.o
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIB)

re: fclean all
