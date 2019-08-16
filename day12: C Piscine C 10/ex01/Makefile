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

SRCS	= ./srcs/main.c ./srcs/cat.c ./srcs/string_utils.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= ft_cat
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
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Single file: ./Makefile$(C_RESET)" ;
	@cat ./Makefile > result-off.txt ;
	@./ft_cat ./Makefile > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Multiple file: ./Makefile ./Makefile$(C_RESET)" ;
	@cat ./Makefile ./Makefile > result-off.txt ;
	@./ft_cat ./Makefile ./Makefile > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Single file: x < ./Makefile$(C_RESET)" ;
	@cat < ./Makefile > result-off.txt ;
	@./ft_cat < ./Makefile > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Pipied: echo Hello | x$(C_RESET)" ;
	@echo Hello | cat > result-off.txt ;
	@echo Hello | ./ft_cat > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Invalid file: ./a$(C_RESET)" ;
	@cat ./a > out 2>result-off.txt || true ;
	@./ft_cat ./a > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Multiple file with invalid: ./Makefile ./a ./Makefile$(C_RESET)" ;
	@cat ./Makefile ./a ./Makefile > out 2>result-off.txt || true ;
	@./ft_cat ./Makefile ./a ./Makefile > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)With folder: ./srcs/$(C_RESET)" ;
	@cat ./srcs/ > out 2>result-off.txt || true ;
	@./ft_cat ./srcs/ > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)With a read-only file: ./read-only.txt$(C_RESET)" ;
	@echo "Hey! I am in read-only!!" > read-only.txt ;
	@chmod -xrw read-only.txt ;
	@cat ./read-only.txt > out 2>result-off.txt || true ;
	@./ft_cat ./read-only.txt > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)With file and directory: ./srcs/ ./Makefile$(C_RESET)" ;
	@cat ./srcs/ ./Makefile > out 2>result-off.txt || true ;
	@./ft_cat ./srcs/ ./Makefile > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@rm -f result-off.txt result-usr.txt out read-only.txt;

.PHONY: all clean fclean re .c.o test