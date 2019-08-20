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
