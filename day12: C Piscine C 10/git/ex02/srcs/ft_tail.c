/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:17:23 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/14 16:17:23 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_tail.h"
#include "ft_tail_utils.h"
#include "ft_tail_out.h"
#include "ft_console_io.h"
#include "ft_args_parser.h"
#include "ft_strncpy.h"

void	stdin_tail(t_options *opts)
{
	do_tail(IN, opts);
}

bool	tail(char *exec, char *path, t_options *opts, int total_count)
{
	static int	current_id = 0;
	int			fd;

	fd = open_file(exec, path);
	if (fd < 0)
		return (false);
	if (total_count > 1)
	{
		if (current_id++ != 0)
			write_str_out("\n");
		write_header(path);
	}
	do_tail(fd, opts);
	return (true);
}

bool	do_tail(int fd, t_options *opts)
{
	if (opts->byte_to_read == NOTHING)
		tail_by_lines(fd);
	else
		tail_by_byte_count(fd, opts->byte_to_read);
	return (true);
}

void	write_header(char *path)
{
	write_str_out("==> ");
	write_str_out(path);
	write_str_out(" <==\n");
}
