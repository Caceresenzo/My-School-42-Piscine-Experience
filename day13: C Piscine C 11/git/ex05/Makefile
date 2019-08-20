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

SRCS	= ./srcs/ft_atoi.c ./srcs/ft_char_write.c ./srcs/ft_is.c ./srcs/ft_number_write.c ./srcs/ft_operation.c ./srcs/ft_str_write.c ./srcs/main.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= do-op
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
	norminette */*.[ch]

find_sources :
	@find srcs -type f -name "*.c" | xargs -I{} echo ./{} | tr '\n' ' '
	
test : re
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with empty$(C_RESET)" ;
	@./${NAME} | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: 1 + 1$(C_RESET)" ;
	@./${NAME} 1 + 1 | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: 42amis - --+-20toto12$(C_RESET)" ;
	@./${NAME} 42amis - --+-20toto12 | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: 1 p 1$(C_RESET)" ;
	@./${NAME} 1 p 1 | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: 1 + toto3$(C_RESET)" ;
	@./${NAME} 1 + toto3 | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: toto3 + 4$(C_RESET)" ;
	@./${NAME} toto3 + 4 | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: foo plus bar$(C_RESET)" ;
	@./${NAME} foo plus bar | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: 25 / 0$(C_RESET)" ;
	@./${NAME} 25 / 0 | cat -e ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Testing with: 25 % 0$(C_RESET)" ;
	@./${NAME} 25 % 0 | cat -e ;
	@##

re : fclean all

.PHONY: all clean fclean re .c.o test
