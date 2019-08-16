/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:10:58 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/13 18:10:59 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include "cat.h"

void	show_error(char *executable, char *path)
{
	if (errno == 0)
		return ;
	str_write(ERR, basename(executable));
	str_write(ERR, ": ");
	str_write(ERR, path);
	str_write(ERR, ": ");
	str_write(ERR, strerror(errno));
	str_write(ERR, "\n");
	errno = 0;
}

void	do_cat(char *executable, char *path, int file_descriptor)
{
	unsigned int	byte_read;
	char			buffer[BUFFER_SIZE];

	while ((byte_read = read(file_descriptor, buffer, BUFFER_SIZE)) > 0)
	{
		if (errno != 0)
		{
			show_error(executable, path);
			break ;
		}
		write(OUT, &buffer[0], byte_read);
	}
	if (file_descriptor > 2)
		close(file_descriptor);
}

void	stdin_loop(void)
{
	do_cat(NULL, NULL, 0);
}

bool	cat(char **paths, int count, int offset)
{
	bool	result;
	int		file_descriptor;
	int		index;
	char	*path;

	result = true;
	index = offset;
	while (index < count + offset)
	{
		path = paths[index];
		file_descriptor = open(path, O_RDONLY);
		if (file_descriptor < 0)
		{
			show_error(paths[0], path);
			result = false;
		}
		else
			do_cat(paths[0], path, file_descriptor);
		index++;
	}
	return (result);
}
