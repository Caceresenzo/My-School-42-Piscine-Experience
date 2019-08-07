/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:22:01 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/03 17:22:08 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_putchar(char c);

void	print_if(bool condition, char if_true, char if_false)
{
	if (condition)
		ft_putchar(if_true);
	else
		ft_putchar(if_false);
}

void	rush(int x, int y)
{
	int		line;
	int		column;
	bool	last_column;

	line = 0;
	while (line < y)
	{
		column = 0;
		while (column < x)
		{
			last_column = column == 0 || column == x - 1;
			if (line == 0 || line == y - 1)
				print_if(last_column, 'o', '-');
			else
				print_if(last_column, '|', ' ');
			column++;
		}
		ft_putchar('\n');
		line++;
	}
}
