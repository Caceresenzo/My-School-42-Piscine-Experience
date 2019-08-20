/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:11:48 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/16 11:11:48 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	x_ft_put_number(int number)
{
	if (number > 9)
		x_ft_put_number(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	if (length <= 0)
		return ;
	(*f)(tab[0]);
	ft_foreach(tab + 1, length - 1, f);
}

int		main(void)
{
	int	index;
	int	*tab;
	int	length;

	length = 10;
	tab = malloc(length * sizeof(int));
	index = 0;
	while (index < length)
	{
		tab[index] = index;
		index++;
	}
	ft_foreach(tab, length, &x_ft_put_number);
}
