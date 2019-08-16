/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:30:48 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/14 12:30:48 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_is_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

bool	ft_is_whitespace(char c)
{
	return (ft_is_in_string(c, "\t\n\v\f\r "));
}

bool	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}
