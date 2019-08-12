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
SOURCES_FOLDER=srcs
HEADERS_FOLDER=includes

all : libft.a

libft.a :
	gcc -I$(HEADERS_FOLDER) -c -Wall -Wextra -Werror $(SOURCES)
	ar -rcs $(NAME) $(OBJECTS)
	mv $(OBJECTS) $(SOURCES_FOLDER)

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	find $(SOURCES_FOLDER) -name "*.o" -type f -maxdepth 1 -delete
