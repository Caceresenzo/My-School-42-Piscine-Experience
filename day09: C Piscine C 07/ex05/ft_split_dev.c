/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:10:16 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/09 12:10:34 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define FIND_OFFSET 2
#define EMPTY_NEEDLE 0
#define NO_MATCH 1

char			*ft_strncpy(char *dest, char *src, unsigned int n)
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

unsigned int	ft_str_find(char *haystack, char *needle, int start, int *size)
{
	char *haystack_start;
	char *needle_start;

	if (*(needle_start = needle) == '\0')
		return (EMPTY_NEEDLE);
	haystack += start;
	haystack_start = haystack;
	while (true)
	{
		if (*needle == '\0')
			return (haystack - haystack_start + FIND_OFFSET);
		if (*haystack == *needle)
			needle++;
		else
			needle = needle_start;
		if (size != 0)
			*size += 1;
		if (*haystack == '\0')
			break ;
		haystack++;
	}
	return (NO_MATCH);
}

int				ft_count_occurrence(char *haystack, char *needle)
{
	int	count;
	int	offset;
	int	result;

	count = 0;
	offset = 0;
	while (true)
	{
		result = ft_str_find(haystack, needle, offset, 0);
		if (result == NO_MATCH || result == EMPTY_NEEDLE)
			break ;
		count++;
		offset += result - FIND_OFFSET;
	}
	return (count);
}

char			**ft_split_dlg(char *str, char *charset, char **arr, int d_len)
{
	int	index;
	int	offset;
	int	result;
	int	size;

	index = 0;
	offset = 0;
	while (index < ft_count_occurrence(str, charset) + 1)
	{
		size = 0;
		result = ft_str_find(str, charset, offset, &size);
		if (result == EMPTY_NEEDLE)
			break ;
		if (!(arr[index] = (char *)malloc((size) * sizeof(char))))
			return (0);
		if (result == NO_MATCH)
			d_len = 0;
		arr[index] = ft_strncpy(arr[index], str + offset, size - d_len);
		if (result == NO_MATCH)
			break ;
		offset += size;
		index++;
	}
	return (arr);
}

char			**ft_split(char *str, char *charset)
{
	int		total_occ;
	char	**array;
	char	*pointer;

	pointer = charset;
	while (*pointer)
		pointer++;
	total_occ = ft_count_occurrence(str, charset);
	if (!(array = (char **)malloc((total_occ + 2) * sizeof(char *))))
		return (0);
	if (!ft_split_dlg(str, charset, array, pointer - charset))
		return (0);
	array[total_occ + 1] = 0;
	return (array);
}

int				main(void)
{
	int		index;
	int		jndex;
	char	*str;
	char	*charset;
	char	**split;

	str = "Hello World From ft_split()";
	charset = " asd";
	printf("TEST [ occurence_count_space ] -> %d\n", ft_count_occurrence(str, " "));
	printf("TEST [ occurence_count_empty ] -> %d\n", ft_count_occurrence(str, ""));
	split = ft_split(str, charset);
	index = 0;
	while (index < ft_count_occurrence(str, charset) + 2)
	{
		printf("split[%d] = \"%s\" (\"", index, split[index]);
		fflush(stdout);
		if (split[index] != 0)
		{
			jndex = 0;
			while (split[index][jndex])
			{
				write(1, &split[index][jndex], 1);
				jndex++;
			}
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[(unsigned char)split[index][jndex] / 16], 1);
			write(1, &"0123456789abcdef"[(unsigned char)split[index][jndex] / 16], 1);
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[(unsigned char)split[index][jndex + 1] % 16], 1);
			write(1, &"0123456789abcdef"[(unsigned char)split[index][jndex + 1] % 16], 1);
		}
		printf("\")\n");
		fflush(stdout);
		index++;
	}
	free(split);
}
