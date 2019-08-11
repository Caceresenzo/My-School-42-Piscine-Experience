/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:35:59 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 18:36:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	write_last_word(char *str)
{
	int	index;
	bool	in_word;
	char	*last_word;

	index = 0;
	last_word = str;
	while (*str)
	{
		if (is_space(*str) && in_word)
			in_word = false;
		else if (!is_space(*str) && !in_word)
		{
			in_word = true;
			last_word = str;
		}
		str++;
	}
	if (last_word == 0)
		return ;
	while (*last_word)
	{
		if (is_space(*last_word))
			break ;
		write(1, last_word, 1);
		last_word++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		write_last_word(argv[1]);
	write(1, "\n", 1);
}
