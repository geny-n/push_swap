# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 10:14:27 by ngeny             #+#    #+#              #
#    Updated: 2024/04/02 17:28:45 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
BONUS_NAME = checker

LIBFT	= ./lib/libft/libft.a
PRINTF	= ./lib/ftprintf/libftprintf.a
GNL 	= ./lib/gnl/gnl.a
BONUS_DIR = ./bonus/
OBJDIR = ./OBJ/
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC =	initialize.c \
			free.c \
			utils.c \
			swap_a_b.c \
			push_a_b.c \
			rotate_a_b.c \
			rev_rotate_a_b.c \
			check_error.c \
			tiny_sort.c \
			sort_push_a_to_b.c \
			sort_push_b_to_a.c \
			move.c 
SRC_MAIN = main.c

BONUS_SRC =	${BONUS_DIR}check_push_a_b.c \
			${BONUS_DIR}check_rev_rotate_a_b.c \
			${BONUS_DIR}check_rotate_a_b.c \
			${BONUS_DIR}check_swap_a_b.c

BONUS_MAIN =	${BONUS_DIR}checker.c \
				${BONUS_DIR}checker_utils.c \

SOURCES = ${SRC} ${SRC_MAIN}
SOURCES_BONUS = ${SRC} ${BONUS_SRC} ${BONUS_MAIN}

OBJ = ${SOURCES:%.c=${OBJDIR}%.o}
BONUS_OBJ = ${SOURCES_BONUS:${BONUS_DIR}%.c=${OBJDIR}%.o}

start :
	make all;

${LIBFT} :
	@make -sC ./lib/libft
${PRINTF} :
	@make -sC ./lib/ftprintf
${GNL} :
	@make -sC ./lib/gnl
	
all: ${NAME}
${NAME} : ${OBJ} ${LIBFT} ${PRINTF} ${GNL}
	${CC} ${FLAGS} ${OBJ} ${LIBFT} ${PRINTF} ${GNL} -o ${NAME}

bonus: ${BONUS_NAME}  
${BONUS_NAME}: ${BONUS_OBJ} ${LIBFT} ${PRINTF} ${GNL}
	${CC} ${FLAGS} ${BONUS_OBJ} ${LIBFT} ${PRINTF} ${GNL} -o ${BONUS_NAME}
	
${OBJDIR}%.o : %.c
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c -o $@ $<
${OBJDIR}%.o : ${BONUS_DIR}%.c
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c -o $@ $<

clean :
	rm -rf $(OBJDIR)
	make clean -C ./lib/libft
	make clean -C ./lib/ftprintf
	make clean -C ./lib/gnl

fclean : clean
	rm -rf ${NAME}
	rm -rf ${BONUS_NAME}
	rm -rf  ${LIBFT}
	rm -rf  ${PRINTF}
	rm -rf  ${GNL}

re : fclean all

.PHONY :
	all clean fclean re
