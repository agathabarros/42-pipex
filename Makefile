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

LIBRARY = pipex.a

PROGRAM = pipex

SRCS = pipex.c pipex_utils.c
OBJS = $(SRCS:.c=.o)

#MAIN = pipex.c
#valgrind --leak-check=full --trace-children=yes

INCLUDE = -I .

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MAKE = make -C 
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

.c.o:		%.o : %.c
					${CC} ${CFLAGS} ${INCLUDE} -c $< -o $(<:.c=.o)

$(PROGRAM): ${LIBRARY}
	@${CC} ${CFLAGS} ${SRCS} -o ${PROGRAM} ${LIBRARY}


$(LIBRARY): ${OBJS} 
	@${MAKE} ${LIBFT_PATH} all
	@cp ${LIBFT} ${LIBRARY}
	@ar rcs ${LIBRARY} ${OBJS} 

all:	${PROGRAM}


clean:
					${MAKE} ${LIBFT_PATH} clean
					${RM} ${OBJS} ${LIBRARY} ${OBJS_BONUS}

fclean: 	clean
					${MAKE} ${LIBFT_PATH} fclean
					${RM} ${PROG}
					
re:			fclean all

.PHONY: all clean fclean re