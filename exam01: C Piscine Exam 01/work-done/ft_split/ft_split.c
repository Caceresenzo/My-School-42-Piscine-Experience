/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 19:12:30 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 19:12:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\t' || c == ' ');
}

int		str_length(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*str_copy(char *src, char *dest, int size)
{
	while (*src && size)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = '\0';
	return (dest);
}

char	*find_next_word(char *str, int *offset, int *length)
{
	int		index;
	char	*curr_word;;

	index = *offset;
	while (str[index])
	{
		if (!is_space(str[index]))
		{
			curr_word = &str[index];
			*length = 1;
			while (!is_space(str[index]) && str[index])
			{
				*offset += 1;
				*length += 1;
				index++;
			}
			return curr_word;
		}
		*offset += 1;
		index++;
	}
	return (0);
}

int		count_words(char *str)
{
	int		count;
	int		offset;
	int		size;
	char	*new_word;
	char	*last_word;

	count = 0;
	offset = 0;
	size = 0;
	last_word = str;
	while (true)
	{
		new_word = find_next_word(str, &offset, &size);
		if (new_word == 0)
			break ;
		count++;
		last_word = new_word;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		index;
	int		offset;
	int		size;
	char	*next_word;
	char	**array;

	array = (char **)malloc((count_words(str) + 1) * sizeof(char *));
	index = 0;
	offset = 0;
	size = 0;
	while (index < count_words(str))
	{
		next_word = find_next_word(str, &offset, &size);
		array[index] = (char *)malloc((str_length(next_word) + 1) * sizeof(char));
		str_copy(&str[offset - (size - 1)], array[index], size - 1);
		index++;
	}
	array[count_words(str)] = NULL;
	return (array);
}
