/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:27:24 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 18:27:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

bool	has_already(char c, bool already[255])
{
	return (already[(unsigned char)c]);
}

void	set_already(char c, bool already[255])
{
	already[(unsigned char)c] = true;
}

void	inter(char *str1, char *str2)
{
	int		index;
	int		jndex;
	int		len1;
	int		len2;
	bool	already[255];

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	index = 0;
	while (index < 255)
	{
		already[index] = false;
		index++;
	}
	index = 0;
	jndex = 0;
	while (index < len1)
	{
		jndex = 0;
		while (jndex < len2)
		{
			if (str1[index] == str2[jndex])
			{
				if (!has_already(str1[index], already))
					write(1, &str1[index], 1);
				set_already(str1[index], already);
			}
			jndex++;
		}
		index++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
}
