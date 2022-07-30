# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:38:32 by bde-biol          #+#    #+#              #
#    Updated: 2022/07/30 11:17:17 by bde-biol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line_utils.c get_next_line.c
OBJS = ${SRCS:.c=.o}

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42
DEBUG_FLAGS = -g -fsanitize=address
AR	= ar rcs
NAME	= gnl.a


all:		${NAME}

.c.o:
	${CC} ${CFLAGS} ${DEBUG_FLAGS} -I includes/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

bonus		: all

main:	${NAME} main.c
		${CC} ${CFLAGS} ${DEBUG_FLAGS} -I includes/ -o main main.c ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

