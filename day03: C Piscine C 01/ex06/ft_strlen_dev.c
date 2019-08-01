/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:31:32 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/01 14:31:36 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (*(str++) != '\0')
	{
		length++;
	}
	return (length);
}

int		main(void)
{
	char	string[15];
	char	*first_pointer;
	int		length;

	string[0] = 'H';
	string[1] = 'e';
	string[2] = 'l';
	string[3] = 'l';
	string[4] = 'o';
	string[5] = ' ';
	string[6] = 'W';
	string[7] = 'o';
	string[8] = 'r';
	string[9] = 'l';
	string[10] = 'd';
	string[11] = ' ';
	string[12] = '4';
	string[13] = '2';
	string[14] = '\0';
	first_pointer = &string[0];
	length = ft_strlen(first_pointer);
	printf("length %d\n", length);
}
