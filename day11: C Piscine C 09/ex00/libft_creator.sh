# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 13:44:03 by ecaceres          #+#    #+#              #
#    Updated: 2019/08/12 13:44:10 by ecaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a
find . -name "*.c" -type f -maxdepth 1 -exec gcc -Wall -Werror -Wextra -c {} \;
ar -rcs libft.a *.o
find . -name "*.o" -type f -maxdepth 1 -delete
