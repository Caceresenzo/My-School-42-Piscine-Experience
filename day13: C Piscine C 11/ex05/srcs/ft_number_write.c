/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:03:07 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/18 17:03:07 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

void	ft_number_write(int number)
{
	if (number == -2147483648)
	{
		ft_number_write(number / 10);
		ft_char_write('8');
	}
	else if (number < 0)
	{
		ft_char_write('-');
		ft_number_write(-number);
	}
	else
	{
		if (number > 9)
			ft_number_write(number / 10);
		ft_char_write('0' + number % 10);
	}
}
