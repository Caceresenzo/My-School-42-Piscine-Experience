/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:59:15 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/12 16:39:44 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool	is_char_in_string(char c, char *set)
{
	while (true)
	{
		if (*set == '\0')
			return (c == '\0');
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

int		count_occur(char *str, char *charset)
{
	int		count;
	char	*previous;
	char	*next;

	count = 0;
	previous = str;
	next = str;
	while (true)
	{
		if (is_char_in_string(*str, charset))
			next = str;
		if (next - previous > 1)
			count++;
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	return (count);
}

int		add_part(char **entry, char *previous, int size, char *charset)
{
	if (is_char_in_string(previous[0], charset))
	{
		previous++;
		size--;
	}
	*entry = (char *)malloc((size + 3) * sizeof(char));
	ft_strncpy(*entry, previous, size);
	(*entry)[size] = '\0';
	(*entry)[size + 1] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		size;
	char	*previous;
	char	*next;
	char	**array;

	array = (char **)malloc((count_occur(str, charset) + 1) * sizeof(char *));
	index = 0;
	previous = str;
	next = str;
	while (true)
	{
		if (is_char_in_string(*str, charset))
			next = str;
		if ((size = next - previous) > 1)
			index += add_part(&array[index], previous, size, charset);
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	array[index] = 0;
	return (array);
}

int		main(int argc, char **argv)
{
	int		index;
	char	**split;

	argc = argc + 0;
	printf("count occ: %d\n", count_occur("  a  b   b   ", " a   "));
	//split = ft_split("ImtmVrV6Ov8QrkGGUglBy7Vgsu iIsdl5XyT35Czv4xeu", "yenORYQ");
	split = ft_split(argv[1], argv[2]);
	index = 0;
	printf("tab start\n");
	while (split[index])
	{
		printf("tab[%d]: $%s$\n", index, split[index]);
		fflush(stdout);
		index++;
	}
	printf("tab end\n");
}
