/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:12:52 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/08 11:12:53 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_str_length(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		ft_compute_final_length(char **strings, int size, int sep_length)
{
	int	final_length;
	int	index;

	final_length = 0;
	index = 0;
	while (index < size)
	{
		final_length += ft_str_length(strings[index]);
		final_length += sep_length;
		index++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sep_length;
	int		full_length;
	int		index;
	char	*read_head;
	char	*string;

	sep_length = ft_str_length(sep);
	full_length = ft_compute_final_length(strs, size, sep_length);
	if (!(string = (char *)malloc((full_length + 1) * sizeof(char))))
		return (0);
	read_head = string;
	index = 0;
	while (index < size)
	{
		ft_strcpy(read_head, strs[index]);
		read_head += ft_str_length(strs[index]);
		if (index < size - 1)
		{
			ft_strcpy(read_head, sep);
			read_head += sep_length;
		}
		index++;
	}
	*read_head = '\0';
	return (string);
}

int		main(void)
{
	char	**strs;
	char	*separator;
	char	*result;

	strs = (char**)malloc(4 * sizeof(strs));
	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "From";
	strs[3] = "strjoin()";
	separator = " ";
	result = ft_strjoin(4, strs, separator);
	printf("result : $%s$\n", result);
	free(result);
}
