# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 20:22:01 by agathabarro       #+#    #+#              #
#    Updated: 2023/08/16 19:30:50 by agathabarro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = pipex

SRCS = pipex.c pipex_utils.c
OBJS = $(SRCS:.c=.o)

#MAIN = pipex.c
#valgrind --leak-check=full --trace-children=yes

INCLUDE = -I .

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MAKE = make -C 
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

.c.o:		%.o : %.c
					${CC} ${CFLAGS} ${INCLUDE} -c $< -o $(<:.c=.o)

${PROG}:	${OBJS}
					${MAKE} ${LIBFT_PATH} all
					${CC} ${OBJS} ${LIBFT} -o ${PROG}

all: 		${PROG}
					
clean:
					${MAKE} ${LIBFT_PATH} clean
					${RM} ${OBJS}

fclean: 	clean
					${MAKE} ${LIBFT_PATH} fclean
					${RM} ${PROG}
					
re:			fclean all

.PHONY: all clean fclean re