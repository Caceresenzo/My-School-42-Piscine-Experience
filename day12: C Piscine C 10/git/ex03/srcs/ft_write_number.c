/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:36:55 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/15 13:36:55 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_write_number.h"

void	ft_buffer_number(int number, int radix, int buffer[], int index)
{
	if (number > radix - 1)
		ft_buffer_number(number / radix, radix, buffer, index + 1);
	buffer[index] = number % radix;
}

void	ft_write_number(unsigned int number, int radix, int char_count)
{
	int	buffer[MAX_BUFFER_SIZE + 1];
	int	index;

	index = -1;
	while (index++ < MAX_BUFFER_SIZE)
		buffer[index] = 0;
	ft_buffer_number(number, radix, buffer, 0);
	index = -1;
	while (index++ < char_count)
		write(1, &"0123456789abcdef"[buffer[char_count - index]], 1);
}

void	ft_write_safe_char(char *c)
{
	if (*c >= ' ' && *c != 127)
		write(1, c, 1);
	else
		write(1, &".", 1);
}
