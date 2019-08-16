/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:29:36 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/15 13:29:36 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_dumper.h"
#include "ft_console_io.h"
#include "ft_write_number.h"
#include "ft_equal.h"

void	ft_dump_content(char *content, int index, UINT line, int max)
{
	write(OUT, "  |", 3);
	index = 0;
	while (index < max)
	{
		ft_write_safe_char(&content[line * 16 + index]);
		index++;
	}
	write(OUT, "|", 1);
}

void	ft_dump_line(t_options *options, char *content, UINT line, int max)
{
	int		index;
	bool	disp_content;

	disp_content = options->disp_cont != 0;
	ft_write_number(line * 16, 16, 6 + disp_content);
	write(1, "  ", 1 + disp_content);
	index = 0;
	while (index < 16)
	{
		if (index >= max)
			write(OUT, "  ", 2);
		else
			ft_write_number(content[line * 16 + index], 16, 1);
		if (index != 16 - 1)
			write(OUT, "  ", 1 + (disp_content && index == 7));
		index++;
	}
	if (disp_content)
		ft_dump_content(content, index, line, max);
	write(OUT, "\n", 1);
}

void	ft_repeat_line(t_options *options, char *content, UINT line, int max)
{
	int	index;

	index = 0;
	if (options->disp_cont < 2)
		ft_dump_line(options, content, line, max);
	else
		while (index < options->disp_cont)
		{
			ft_dump_line(options, content, line, max);
			index++;
		}
}

void	ft_do_dump(t_options *options, char *content, UINT length, UINT lines)
{
	unsigned int	i;
	int				max;
	char			*last_line;
	bool			star_flag;

	i = -1;
	last_line = 0;
	star_flag = false;
	while (++i < lines)
	{
		max = (i == lines - 1) ? length % 16 : 16;
		if (last_line != 0 && ft_is_equal(content + (i * 16), last_line, 16))
		{
			write(OUT, "*\n", !star_flag ? 2 : 0);
			star_flag = true;
		}
		else
		{
			star_flag = false;
			if (max != 0)
				ft_repeat_line(options, content, i, max);
		}
		last_line = content + (i * 16);
	}
	ft_write_number((i - 1) * 16 + max, 16, 6 + (options->disp_cont != 0));
}

void	ft_dump(t_options *options, char *content, UINT length, UINT lines)
{
	if (length == 0)
		return ;
	ft_do_dump(options, content, length, lines);
	write(OUT, "\n", 1);
}
