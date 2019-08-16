/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:29:38 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/14 12:29:38 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "ft_is.h"

bool	ft_is_operator(char c)
{
	return (ft_is_in_string(c, "+-"));
}

int		ft_abs_strict_atoi(char *str)
{
	int	result;

	result = 0;
	while (ft_is_whitespace(*str) || ft_is_operator(*str))
		str++;
	while (ft_is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (result);
}
