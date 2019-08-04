/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 18:54:26 by exam              #+#    #+#             */
/*   Updated: 2019/08/02 18:54:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_str_length(const char *str)
{
	int index;

	index = 0;
	while (str[index++] != '\0');
	return (index - 1);
}

int		ft_pow(int a, int b)
{
	int	result;

	result = 1;
	while (a-- != 0 && a > 0)
	{
		result *= b;
	}
	return (result);
}

void	ft_remove_excess(int *number, int index, int str_length)
{
	while ((str_length - index) != 0)
	{
		*number /= 10;
		index++;
	}
}

int		ft_atoi(const char* str)
{
	int		result;
	int		str_length;
	int		index;
	bool    negative;

	result = 0;
	str_length = ft_str_length(str);
	negative = str[0] == '-';
	index = negative;
	while(index <= str_length - 1)
	{
		if (!(str[index] >= '0' && str[index] <= '9'))
		{
			ft_remove_excess(&result, index, str_length);
			break ;
		}
		result += (str[index] - '0') * ft_pow(str_length - index, 10);
		index++;
	}
	if (negative)
		result = -result;
	return (result);
}
