/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:05:51 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 19:05:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int		*ft_range(int start, int end)
{
	int	index;
	int	bound;
	int	*array;
	bool	inversed;

	if ((inversed = start > end))
		ft_swap(&start, &end);
	bound = end - start + 1;
	if (!(array = malloc((bound + 2) * sizeof(int))))
		return (NULL);
	index = 0;
	while (index < bound)
	{
		if (inversed)
			array[bound - 1 - index] = start + index;
		else
			array[index] = start + index;
		index++;
	}
	return (array);
}
