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

SRCS	= ./srcs/ft_args_parser.c ./srcs/ft_console_io.c ./srcs/ft_dumper.c ./srcs/ft_equal_buffer.c ./srcs/ft_file_utils.c ./srcs/ft_file_utils2.c ./srcs/ft_hexdump.c ./srcs/ft_strncpy.c ./srcs/ft_write_number.c ./srcs/main.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= ft_hexdump
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
	
test : re
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Single file: ./Makefile$(C_RESET)" ;
	@hexdump ./Makefile | cat -e > result-off.txt ;
	@./ft_hexdump ./Makefile | cat -e > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Single file with -C: ./Makefile$(C_RESET)" ;
	@hexdump -C ./Makefile | cat -e > result-off.txt ;
	@./ft_hexdump -C ./Makefile | cat -e > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Single file with -C -C: ./Makefile$(C_RESET)" ;
	@hexdump -C -C ./Makefile | cat -e > result-off.txt ;
	@./ft_hexdump -C -C ./Makefile | cat -e > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)STDIN: x < ./Makefile$(C_RESET)" ;
	@hexdump < ./Makefile | cat -e > result-off.txt ;
	@./ft_hexdump < ./Makefile | cat -e > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Multiple file: ./Makefile ./Makefile$(C_RESET)" ;
	@hexdump ./Makefile ./Makefile | cat -e > result-off.txt ;
	@./ft_hexdump ./Makefile ./Makefile | cat -e > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Multiple file with -C: ./Makefile ./Makefile$(C_RESET)" ;
	@hexdump -C ./Makefile ./Makefile | cat -e > result-off.txt ;
	@./ft_hexdump -C ./Makefile ./Makefile | cat -e > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ SHOULD NOT HAVE DIFF ]$(C_RESET) $(C_WHITE)Multiple file with -C -C: ./Makefile ./Makefile$(C_RESET)" ;
	@hexdump -C -C ./Makefile ./Makefile | cat -e > result-off.txt ;
	@./ft_hexdump -C -C ./Makefile ./Makefile | cat -e > result-usr.txt ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Invalid file: ./a$(C_RESET)" ;
	@hexdump -C -C ./a > out 2>result-off.txt || true ;
	@./ft_hexdump -C -C ./a > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Valid and invalid file: ./Makefile ./a ./Makefile$(C_RESET)" ;
	@hexdump ./Makefile ./a ./Makefile > out 2>result-off.txt || true ;
	@./ft_hexdump ./Makefile ./a ./Makefile > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Only invalid file: ./a ./b ./c$(C_RESET)" ;
	@hexdump ./a ./b ./c > out 2>result-off.txt || true ;
	@./ft_hexdump ./a ./b ./c > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)On directory: ./srcs/$(C_RESET)" ;
	@hexdump ./srcs/ > out 2>result-off.txt || true ;
	@./ft_hexdump ./srcs/ > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)On 2 directory: ./srcs/ ./srcs/$(C_RESET)" ;
	@hexdump ./srcs/ ./srcs/ > out 2>result-off.txt || true ;
	@./ft_hexdump ./srcs/ ./srcs/ > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Illegal argument: -a$(C_RESET)" ;
	@hexdump -a > out 2>result-off.txt || true ;
	@./ft_hexdump -a > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_LIGHT_RED_B)[ MUST HAVE DIFF       ]$(C_RESET) $(C_WHITE)Read only file: read_only.txt$(C_RESET)" ;
	@echo "Hey! This file is supposed to not be redeable..." > read_only.txt
	@chmod -xrw read_only.txt
	@hexdump read_only.txt > out 2>result-off.txt || true ;
	@./ft_hexdump read_only.txt > out 2>result-usr.txt || true ;
	@git --no-pager diff --no-index result-usr.txt result-off.txt || true ;
	@##
	@rm -f result-off.txt result-usr.txt out read_only.txt;

re : fclean all

.PHONY: all clean fclean re .c.o test