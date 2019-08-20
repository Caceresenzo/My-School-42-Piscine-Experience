/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:22:59 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/16 11:22:59 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*results;

	if (!(results = malloc(length * sizeof(int))))
		return (NULL);
	index = 0;
	while (index < length)
	{
		results[index] = (*f)(tab[index]);
		index++;
	}
	return (results);
}

int	ft_square(int number)
{
	return (number * number);
}

int	main(void)
{
	int	index;
	int	*tab;
	int	length;
	int	*results;

	length = 10;
	tab = malloc(length * sizeof(int));
	index = 0;
	while (index < length)
	{
		tab[index] = index;
		index++;
	}
	results = ft_map(tab, length, &ft_square);
	index = 0;
	while (index < length)
	{
		printf("[mapped] square(%d) = %d\n", index, results[index]);
		index++;
	}
}
