/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:17:06 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/15 12:17:06 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libgen.h>

#include "ft_args_parser.h"
#include "ft_console_io.h"
#include "ft_hexdump.h"

#define ERR_ILLG_OPT "illegal option"

#define HAS_MORE (index + 1 < count)

int		count_same_letter(t_options *options, char letter, char *str)
{
	int		count;
	int		index;

	count = 0;
	index = 1;
	while (str[index])
	{
		if (str[index] == letter)
			count++;
		else
		{
			display_error(options, ERR_ILLG_OPT, str + index, true);
			display_usage(options);
			return (-1);
		}
		index++;
	}
	return (count);
}

bool	parse_args(char **args, int count)
{
	t_options	options;
	int			index;
	int			offset;
	char		*arg;

	options.executable = args[0];
	options.disp_cont = 0;
	index = 1;
	while (index < count)
	{
		arg = args[index];
		if (arg[0] == '-' && arg[1] != '\0')
		{
			offset = count_same_letter(&options, 'C', arg);
			if (offset == -1)
				return (false);
			options.disp_cont++;
		}
		else
			break ;
		index++;
	}
	return (process_files(args, count, index, &options));
}

bool	process_files(char **args, int count, int index, t_options *options)
{
	int		total;

	total = count - index;
	if (total == 0)
		return (ft_stdin_hexdump(options));
	options->paths = args + index;
	return (ft_hexdump(options, total));
}

void	display_usage(t_options *options)
{
	write_str_err("usage: ");
	write_str_err(basename(options->executable));
	write_str_err(" [-C] [file ...]\n");
}

void	display_error(t_options *options, char *error, char *cause, bool limit)
{
	write_str_err(basename(options->executable));
	write_str_err(": ");
	write_str_err(error);
	write_str_err(" -- ");
	if (limit)
		write_char_err(*cause);
	else
		write_str_err(cause);
	write_str_err("\n");
}
