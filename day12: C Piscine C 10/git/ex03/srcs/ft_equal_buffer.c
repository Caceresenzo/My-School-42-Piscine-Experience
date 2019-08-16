/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:02:55 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/15 19:02:55 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_is_equal(char *a, char *b, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < size)
	{
		if ((unsigned char)a[index] != (unsigned char)b[index])
			return (false);
		index++;
	}
	return (true);
}
