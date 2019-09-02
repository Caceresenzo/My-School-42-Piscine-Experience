/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:37:22 by exam              #+#    #+#             */
/*   Updated: 2019/08/23 10:37:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#define CASE_OFFSET 0x20

bool	ft_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool	ft_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

void	ft_ulstr(char *str)
{
	char	current;

	while ((current = *str))
	{
		if (ft_is_uppercase(current))
			current += CASE_OFFSET;
		else if (ft_is_lowercase(current))
			current -= CASE_OFFSET;
		write(1, &current, 1);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_ulstr(argv[1]);
	write(1, "\n", 1);
}
