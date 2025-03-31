# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 13:19:10 by anvacca           #+#    #+#              #
#    Updated: 2025/03/31 12:07:59 by anvacca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			:=	cub3d

VPATH		:=	src \
				src/parsing \
				src/utils \

SRC			:=	main.c

PARSING		:=	check_args.c	\
				error_args.c	\
				parser.c		\

UTILS		:=	ft_strcmp.c		\
				ft_strlen.c		\


SOURCES		:= ${SRC} ${PARSING}
OBJ_DIR		:= obj
OBJECTS		:=	${SOURCES:%.c=${OBJ_DIR}/%.o}

# Libraries
MINILIBX	:=	includes/.MiniLibX

# Variables
CC			:=	cc
CFLAGS		:=  -Wall -Wextra -Iincludes -O2
LIBXFLAGS	:=	-L${MINILIBX} -lmlx -lX11 -lXext -lm

# Makefile
all:	clone_mlx	| ${EXE}

clone_mlx:
	git submodule update --init --recursive

${EXE}:			${OBJECTS}
				@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
				@${CC} ${CFLAGS} ${OBJECTS} ${LIBXFLAGS} -o ${EXE}

${OBJ_DIR}/%.o:	%.c | ${OBJ_DIR}
				@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}:
				@mkdir -p $@

clean:
				@${MAKE} -C ${MINILIBX} clean > /dev/null
				@rm -rf obj

fclean:			clean
				@rm -rf ${EXE}

re:				fclean all

.PHONY:			all clean fclean re
