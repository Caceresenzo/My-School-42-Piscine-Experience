/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:03:22 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/06 15:03:24 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#define BOARD_SIZE 10

bool	is_queen_at_risk(int board[][BOARD_SIZE], int at_x, int at_y)
{
	int	x;
	int	y;
	int	offsets[2];

	offsets[0] = at_y - at_x;
	offsets[1] = at_y + at_x;
	x = 0;
	while (x < BOARD_SIZE)
	{
		y = 0;
		while (y < BOARD_SIZE)
		{
			if (x == at_x || y == at_y
				|| y == x + offsets[0] || y == -x + offsets[1])
				if (board[y][x])
					return (true);
			y++;
		}
		x++;
	}
	return (false);
}

void	clear_column(int board[][BOARD_SIZE], int x)
{
	int	index;

	index = 0;
	while (index < BOARD_SIZE)
	{
		board[index++][x] = false;
	}
}

void	print_queen_position(int board[][BOARD_SIZE])
{
	int	y;
	int	column;

	y = 0;
	while (y < BOARD_SIZE)
	{
		column = 0;
		while (column < BOARD_SIZE)
		{
			if (board[y][column])
			{
				write(1, &"0123456789"[column], 1);
				break ;
			}
			column++;
		}
		y++;
	}
	write(1, "\n", 1);
}

bool	recursive_find(int board[][BOARD_SIZE], int x, int *soluce)
{
	int	y;

	if (x >= BOARD_SIZE)
		return (true);
	y = 0;
	while (y < BOARD_SIZE)
	{
		if (!is_queen_at_risk(board, x, y))
		{
			board[y][x] = true;
			if (recursive_find(board, x + 1, soluce))
			{
				*soluce += 1;
				print_queen_position(board);
			}
			board[y][x] = false;
		}
		y++;
	}
	return (false);
}

int		ft_ten_queens_puzzle(void)
{
	int	soluce;
	int	board[BOARD_SIZE][BOARD_SIZE];
	int	column;

	soluce = 0;
	column = 0;
	while (column++ < BOARD_SIZE)
		clear_column(board, column - 1);
	recursive_find(board, 0, &soluce);
	return (soluce);
}
