/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:09:41 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 18:25:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	add_13(char c)
{
	unsigned char	ch;
	char			max;

	if (is_lower(c))
		max = 'z';
	else
		max = 'Z';
	ch = c + 13;
	if (ch > max)
		ch -= 26;
	return ch;
}

void	rot13(char *str)
{
	while (*str)
	{
		if (is_lower(*str) || is_upper(*str))
			*str = add_13(*str);
		write(1, str, 1);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rot13(argv[1]);
	write(1, "\n", 1);
}
