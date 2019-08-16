/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:51:14 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/15 12:51:14 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <stdbool.h>

# include "ft_args_parser.h"

bool	ft_stdin_hexdump(t_options *options);

bool	ft_hexdump(t_options *options, int count);

#endif
