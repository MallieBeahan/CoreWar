# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 15:10:04 by mbeahan           #+#    #+#              #
#    Updated: 2019/09/10 16:50:39 by mbeahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := asm

SRC :=	asm_main.c \
		validate.c

CFLAGS := -ggdb -Wall -Wextra -Werror
HEADER := -I ../libft/includes
LIB := -L ../libft -lft -L ../ft_printf -lftprintf

all: $(NAME)

$(NAME): $(SRC)
	make -C ../libft
	make -C ../ft_printf
	gcc $(CFLAGS) $(HEADER) $(SRC) $(LIB) -o $(NAME)

clean:
	make -C ../libft clean
	make -C ../ft_printf clean

fclean:
	make -C ../libft fclean
	make -C ../ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean flcean all re