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

SRCS	= ./srcs/ft_abs.c ./srcs/ft_args_parser.c ./srcs/ft_atoi.c ./srcs/ft_console_io.c ./srcs/ft_is.c ./srcs/ft_strncpy.c ./srcs/ft_tail.c ./srcs/ft_tail_out.c ./srcs/ft_tail_utils.c ./srcs/main.c 
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= ft_tail
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
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Single file: ./srcs/ft_abs.c$(C_RESET)" ;
	@tail ./srcs/ft_abs.c > result-off.txt ;
	@./ft_tail ./srcs/ft_abs.c > result-usr.txt ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Multiple file: ./srcs/ft_abs.c ./srcs/ft_abs.c$(C_RESET)" ;
	@tail ./srcs/ft_abs.c ./srcs/ft_abs.c > result-off.txt ;
	@./ft_tail ./srcs/ft_abs.c ./srcs/ft_abs.c > result-usr.txt ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)From STDIN: x < ./Makefile$(C_RESET)" ;
	@tail < ./Makefile > result-off.txt ;
	@./ft_tail < ./Makefile > result-usr.txt ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)From STDIN: x < ./srcs/ft_abs.c$(C_RESET)" ;
	@tail < ./srcs/ft_abs.c > result-off.txt ;
	@./ft_tail < ./srcs/ft_abs.c > result-usr.txt ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)From file and from STDIN (priority test): x ./srcs/ft_abs.c < ./srcs/ft_abs.c$(C_RESET)" ;
	@tail ./srcs/ft_abs.c < ./srcs/ft_abs.c > result-off.txt ;
	@./ft_tail ./srcs/ft_abs.c < ./srcs/ft_abs.c > result-usr.txt ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Multiple file with -c 25: ./srcs/ft_abs.c ./srcs/ft_abs.c$(C_RESET)" ;
	@tail -c 25 ./srcs/ft_abs.c ./srcs/ft_abs.c > result-off.txt ;
	@./ft_tail -c 25 ./srcs/ft_abs.c ./srcs/ft_abs.c > result-usr.txt ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)With directory: ./includes/$(C_RESET)" ;
	@tail ./includes/ > result-off.txt ;
	@./ft_tail ./includes/ > result-usr.txt ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)On 2 directory: ./srcs/ ./srcs/$(C_RESET)" ;
	@tail ./srcs/ ./srcs/ > result-off.txt || true ;
	@./ft_tail ./srcs/ ./srcs/ > result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)On a random binary file: ./tests/random.bin$(C_RESET)" ;
	@tail ./tests/random.bin > result-off.txt || true ;
	@./ft_tail ./tests/random.bin > result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)On a random binary file: ./tests/random2.bin$(C_RESET)" ;
	@tail ./tests/random2.bin > result-off.txt || true ;
	@./ft_tail ./tests/random2.bin > result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)On a random binary file with -c 200: ./tests/random.bin$(C_RESET)" ;
	@tail -c 200 ./tests/random.bin > result-off.txt || true ;
	@./ft_tail -c 200 ./tests/random.bin > result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)On a random binary file with -c 200: ./tests/random.bin2$(C_RESET)" ;
	@tail -c 200 ./tests/random2.bin > result-off.txt || true ;
	@./ft_tail -c 200 ./tests/random2.bin > result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)On a empty file: ./tests/empty$(C_RESET)" ;
	@touch ./tests/empty
	@tail ./tests/empty > out 2>result-off.txt || true ;
	@./ft_tail ./tests/empty > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)On a empty file with STDIN: ./tests/empty$(C_RESET)" ;
	@tail < ./tests/empty > out 2>result-off.txt || true ;
	@./ft_tail < ./tests/empty > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Error -> double -c: -c 25 -c 26$(C_RESET)" ;
	@tail -c 25 -c 26 > out 2>result-off.txt || true ;
	@./ft_tail -c 25 -c 26 > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Error -> double -c but not completed: -c 25$(C_RESET)" ;
	@tail -c 25 -c > out 2>result-off.txt || true ;
	@./ft_tail -c 25 -c > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Error -> illegal -c value: -c 25a$(C_RESET)" ;
	@tail -c 25a > out 2>result-off.txt || true ;
	@./ft_tail -c 25a > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Multiple file with invalid: ./srcs/ft_abs.c a ./srcs/ft_abs.c$(C_RESET)" ;
	@tail -c 25 ./srcs/ft_abs.c a ./srcs/ft_abs.c > out 2>result-off.txt || true ;
	@./ft_tail -c 25 ./srcs/ft_abs.c a ./srcs/ft_abs.c > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index --text result-usr.txt result-off.txt || true ;
	@##
	@rm result-off.txt result-usr.txt out ./tests/empty ;

.PHONY: all clean fclean re .c.o test
