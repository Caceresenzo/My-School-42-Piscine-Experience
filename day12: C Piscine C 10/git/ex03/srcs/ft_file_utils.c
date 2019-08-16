/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:15:42 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/15 13:15:42 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libgen.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "ft_file_utils.h"
#include "ft_console_io.h"
#include "ft_args_parser.h"
#include "ft_strncpy.h"

#define IS_STD(fd) (fd >= 0 && fd <= 2)
#define HAS_ERR (errno != 0)

int		ft_open_file(t_options *options)
{
	return (open(options->curr_path, O_RDONLY));
}

int		ft_close_file(int fd)
{
	return (close(fd));
}

bool	ft_show_error(t_options *options)
{
	if (errno == 0)
		return (false);
	write_str_err(basename(options->executable));
	write_str_err(": ");
	write_str_err(options->curr_path);
	write_str_err(": ");
	write_str_err(strerror(errno));
	write_str_err("\n");
	errno = 0;
	return (true);
}

char	*ft_read_multiple(t_options *opts, int count, UINT *len, int total)
{
	unsigned int	ok_read;
	unsigned int	old_length;
	char			*dest;
	int				index;
	int				fd;

	ok_read = 0;
	dest = NULL;
	index = 0;
	while (index < count)
	{
		opts->curr_path = opts->paths[index];
		fd = ft_open_file(opts);
		ok_read += errno == 0 ? 1 : 0;
		if (errno != 0)
			ft_show_error(opts);
		old_length = *len;
		dest = ft_extend_array(dest, ft_read_full(fd, len), old_length, len);
		if ((index == total - 1 && HAS_ERR && ok_read == 0) || errno == EISDIR)
			ft_show_error(opts);
		index++;
		ft_close_file(fd);
		errno = 0;
	}
	return (dest);
}

char	*ft_read_full(int fd, unsigned int *length)
{
	unsigned int	total_read;
	unsigned int	byte_read;
	char			buffer[BUFFER_SIZE_1K];
	char			*old;
	char			*dest;

	total_read = 0;
	dest = malloc(0);
	while ((byte_read = read(fd, buffer, BUFFER_SIZE_1K)) != 0)
	{
		if (errno != 0)
			return (dest);
		old = dest;
		if (!(dest = malloc((total_read + byte_read) * sizeof(char *))))
			return (0);
		ft_strncpy(dest, old, total_read);
		ft_strncpy(dest + total_read, buffer, byte_read);
		total_read += byte_read;
		free(old);
	}
	*length += total_read;
	return (dest);
}
