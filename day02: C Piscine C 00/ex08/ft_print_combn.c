/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:05:51 by ecaceres          #+#    #+#             */
/*   Updated: 2019/07/31 19:05:54 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_combo(int n, int holders[])
{
	int		index;
	bool	last;

	index = 0;
	while (index < n)
	{
		ft_putchar(48 + holders[index]);
		index++;
	}
	index = n - 1;
	last = true;
	while (index >= 0)
	{
		if (holders[index] != 9 - (n - 1 - index))
		{
			last = false;
			break ;
		}
		index--;
	}
	if (!last)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn_recursive(int n, int curr, int holders[], int st_index)
{
	int index;
	int max;

	if (curr == n)
	{
		ft_write_combo(n, holders);
	}
	else
	{
		max = 10 - (n - curr);
		index = st_index + 1;
		while (index <= max)
		{
			holders[curr] = index;
			ft_print_combn_recursive(n, curr + 1, holders, index);
			index++;
		}
	}
}

void	ft_print_combn(int n)
{
	int holders[10];
	int index;

	index = 0;
	while (index < n)
	{
		holders[index] = 0;
		index++;
	}
	ft_print_combn_recursive(n, 0, holders, -1);
}
