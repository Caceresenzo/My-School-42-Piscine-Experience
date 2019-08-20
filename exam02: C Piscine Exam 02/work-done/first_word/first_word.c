/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:10:48 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 18:10:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	print_first_word(char *str)
{
	int		index;
	int		offset;
	char	*word;

	index = 0;
	word = str;
	while (is_space(str[index]))
		index++;
	offset = index;
	while (true)
	{
		if (str[index] == '\0')
			break ;
		if (is_space(str[index]))
			break ;
		index++;
	}
	if (word != 0)
		write(1, word + offset, index - offset);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_first_word(argv[1]);
	write(1, "\n", 1);
}
