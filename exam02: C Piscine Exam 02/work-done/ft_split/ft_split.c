/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:22:42 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 19:22:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		count_word(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		while (!is_whitespace(*str) && *str != '\0')
			str++;
		count++;
	}
	return (count);
}

char	*ft_strndup(char *str, unsigned int n)
{
	unsigned int	index;
	unsigned int	length;
	char		*dup;

	length = 0;
	while (str[length])
		length++;
	if (length > n)
		length = n;
	if (!(dup = malloc((length + 1) * sizeof(char))))
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char    **ft_split(char *str)
{
	int		index;
	int		word_count;
	char	*word_start;
	char	**array;

	word_count = count_word(str);
	if (!(array = malloc((word_count + 1) * sizeof(char *))))
		return (NULL);
	index = 0;
	while (*str)
	{
		while (is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		word_start = str;
		while (!is_whitespace(*str) && *str != '\0')
			str++;
		array[index] = ft_strndup(word_start, str - word_start);
		index++;
	}
	array[index] = 0;
	return (array);
}
