/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:07:43 by exam              #+#    #+#             */
/*   Updated: 2019/08/23 11:07:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int		ft_str_length(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_union_print_if(bool already[255], char c)
{
	if (!already[(int)c])
	{
		already[(int)c] = true;
		write(1, &c, 1);
	}
}

void	ft_union_do_str(bool already[255], char *str)
{
	int	index;
	int	length;

	index = 0;
	length = ft_str_length(str);
	while (index < length)
	{
		ft_union_print_if(already, str[index]);
		index++;
	}
}

void	ft_union(char *str1, char *str2)
{
	int	index;
	bool	already[255];

	index = 0;
	while (index < 255)
	{
		already[index] = false;
		index++;
	}
	ft_union_do_str(already, str1);
	ft_union_do_str(already, str2);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
}
