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

void	tail_by_lines(int fd)
{
	unsigned int	index;
	int				line_count;
	char			*content;
	char			*last_line;

	index = 0;
	line_count = 0;
	content = read_full(fd);
	while (content[index])
		if (content[index++] == '\n' && content[index] != '\0')
			line_count++;
	index = 0;
	while (*content)
	{
		if (*content == '\n')
		{
			if (++index > (unsigned int)(line_count - DEFAULT_LINE_COUNT + 1))
			{
				write_str_out(last_line);
				break ;
			}
			last_line = content + 1;
		}
		content++;
	}
}

void	tail_by_byte_count(int fd, unsigned int byte_to_read)
{
	unsigned int	index;
	unsigned int	byte_read;
	char			*content;

	index = 0;
	byte_read = 0;
	content = read_full(fd);
	while (content[index++])
		byte_read++;
	index = 0;
	while (*content)
	{
		if (index++ > byte_read - byte_to_read - 1)
		{
			write_str_out(content);
			break ;
		}
		content++;
	}
}
