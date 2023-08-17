# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 16:02:50 by agpereir          #+#    #+#              #
#    Updated: 2023/05/30 17:50:36 by agpereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = libftprintf.a

SRC = ft_printf.c ft_print_std.c ft_print_unsig.c ft_print_pointer.c ft_print_hex.c ft_utils.c 

OBJS = ${SRC:.c=.o}

INCLUDE = -I .
CC = cc
RM = rm -f
MAKE = make -C
CFLAGS = -Wall -Wextra -Werror -g
CP = cp
AR = ar rcs

.o:.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${AR} ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

test: main.c ${NAME}
		${CC} -g ${CFLAGS} ${INCLUDE} main.c ${NAME} -o test

.PHONY: all clean fclean re
