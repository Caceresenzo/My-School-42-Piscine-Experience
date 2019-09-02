/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:24:20 by exam              #+#    #+#             */
/*   Updated: 2019/08/23 10:24:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*rev_print(char *str)
{
	int	index;
	int	size;

	size = 0;
	while (str[size])
		size++;
	index = 0;
	while (index < size)
	{
		write(1, &str[size - 1 - index], 1);
		index++;
	}
	return (str);
}
