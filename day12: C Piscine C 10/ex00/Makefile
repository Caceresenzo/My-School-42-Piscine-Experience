# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 15:11:33 by ecaceres          #+#    #+#              #
#    Updated: 2019/08/13 15:11:34 by ecaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_YELLOW_B=\033[1;33m
C_LIGHT_RED_B=\033[0;91m
C_WHITE=\033[0;97m
C_RESET=\033[0;39m

SRCS	= ./srcs/main.c ./srcs/display_file.c ./srcs/string_utils.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= ft_display_file
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

re : fclean all

test : re
	@echo "I am a file content" > dummy_file.txt
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)No file$(C_RESET)" ;
	@./ft_display_file || true;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Single file: ./dummy_file.txt$(C_RESET)" ;
	@./ft_display_file ./dummy_file.txt || true;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Multiple file: ./dummy_file.txt ./dummy_file.txt$(C_RESET)" ;
	@./ft_display_file ./dummy_file.txt ./dummy_file.txt || true;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Invalid file: ./a$(C_RESET)" ;
	@./ft_display_file ./a || true;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)On directory: ./srcs/$(C_RESET)" ;
	@./ft_display_file ./srcs/ || true;
	@##
	@rm -f result-off.txt result-usr.txt dummy_file.txt ;

.PHONY: all clean fclean re .c.o test