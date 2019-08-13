# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 12:36:23 by ecaceres          #+#    #+#              #
#    Updated: 2019/08/12 12:36:25 by ecaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SOURCES=./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJECTS=ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
OBJECTS_MOVED=./srcs/ft_putchar.o ./srcs/ft_putstr.o ./srcs/ft_strcmp.o ./srcs/ft_strlen.o ./srcs/ft_swap.o
SOURCES_FOLDER=srcs
HEADERS_FOLDER=includes

all : libft.a

libft.a :
	gcc -I$(HEADERS_FOLDER) -c -Wall -Wextra -Werror $(SOURCES)
	mv $(OBJECTS) $(SOURCES_FOLDER)
	ar -rcs $(NAME) $(OBJECTS_MOVED)

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJECTS_MOVED)
