/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:59:11 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/16 11:59:12 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < length)
	{
		if ((*f)(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}

int	ft_is_first_x(char *str)
{
	if (*str == 'X')
		return (1);
	return (0);
}

int	main(void)
{
	int		length;
	char	**array;

	length = 5;
	array = malloc(length * sizeof(char *));
	array[0] = "O";
	array[1] = "X";
	array[2] = "O";
	array[3] = "X";
	array[4] = "O";
	printf("ft_count_if(...) = %d\n",
		ft_count_if(array, length, &ft_is_first_x));
}
