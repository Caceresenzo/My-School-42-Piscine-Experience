/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:52:07 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/14 19:52:07 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>

#include "ft_tail.h"
#include "ft_tail_utils.h"
#include "ft_console_io.h"

int		count_line(unsigned long byte_read, char *content)
{
	unsigned long	index;
	int				line_count;

	index = 0;
	line_count = 0;
	while (index < byte_read)
	{
		if (content[index] == '\n' && index != byte_read - 1)
			line_count++;
		index++;
	}
	return (line_count);
}

void	tail_by_lines(int fd)
{
	unsigned long	byte_read;
	unsigned long	index;
	int				line_count;
	char			*content;
	unsigned int	last_index;

	content = read_full(fd, &byte_read);
	line_count = count_line(byte_read, content);
	index = -1;
	while (++index < byte_read)
	{
		if (content[index] == '\n')
		{
			if (--line_count < DEFAULT_LINE_COUNT)
			{
				while (index < byte_read - 1)
				{
					write(1, content + index + 1, 1);
					index++;
				}
				break ;
			}
			last_index = index + 1;
		}
	}
}

void	tail_by_byte_count(int fd, unsigned int byte_to_read)
{
	unsigned long	index;
	unsigned long	byte_read;
	char			*content;

	content = read_full(fd, &byte_read);
	index = 0;
	while (index < byte_read - byte_to_read)
		index++;
	while (index < byte_read)
	{
		write(1, content + index, 1);
		index++;
	}
}
