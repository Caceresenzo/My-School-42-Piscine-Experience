/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:38:11 by exam              #+#    #+#             */
/*   Updated: 2019/08/23 11:38:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f'
			|| c == '\n' || c == '\r');
}

int		ft_split_count_word(char *str)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (ft_is_whitespace(str[index]))
			index++;
		if (str[index] == '\0')
			break ;
		while (!ft_is_whitespace(str[index]) && str[index] != '\0')
			index++;
		count++;
	}
	return (count);
}

char	*ft_str_n_duplicate(char *str, int n)
{
	int		index;
	char	*duplicate;

	if (!(duplicate = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	index = 0;
	while (str[index] && index < n)
	{
		duplicate[index] = str[index];
		index++;
	}
	while (index < n + 1)
	{
		duplicate[index] = '\0';
		index++;
	}
	return (duplicate);
}

char	**ft_split(char *str)
{
	int		index;
	int		words;
	char	*start;
	char	**array;

	index = 0;
	words = ft_split_count_word(str);
	if (!(array = (char **)malloc((words + 1) * sizeof(char *))))
		return (NULL);
	while (index < words)
	{
		while (ft_is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		start = str;
		while (!ft_is_whitespace(*str) && *str != '\0')
			str++;
		array[index] = ft_str_n_duplicate(start, str - start);
		index++;
	}
	array[index] = 0;
	return (array);
}
