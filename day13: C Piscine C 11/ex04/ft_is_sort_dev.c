/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:36:30 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/20 17:04:13 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		index;
	int		sorted;

	sorted = 1;
	index = 0;
	while (index < length - 1 && sorted)
	{
		if ((*f)(tab[index], tab[index + 1]) < 0)
			sorted = 0;
		index++;
	}
	if (sorted != 1)
	{
		sorted = 1;
		index = 0;
		while (index < length - 1)
		{
			if ((*f)(tab[index], tab[index + 1]) > 0)
				return (0);
			index++;
		}
	}
	return (1);
}

int		ft_less_than(int a, int b)
{
	return (b - a);
}

int		ft_more_than(int a, int b)
{
	return (a - b);
}

int		main(void)
{
	static int	tabx[] = { 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 6, 7 };
	int			index;
	int			*tab;
	int			length;

	length = 10;
	tab = malloc(length * sizeof(int));
	index = 0;
	while (index < length)
	{
		tab[index] = index;
		index++;
	}
	printf("ft_is_sorted(1.........10) = %d\n", ft_is_sort(tab, length, &ft_less_than));
	index = 0;
	while (index < length)
	{
		tab[length - 1 - index] = index;
		index++;
	}
	printf("ft_is_sorted(10.........1) = %d\n", ft_is_sort(tab, length, &ft_more_than));
	tab[5] = 100;
	printf("ft_is_sorted(10...100...1) = %d\n", ft_is_sort(tab, length, &ft_more_than));
	tab[5] = 4;
	tab[9] = 100;
	printf("ft_is_sorted(10.....1.100) = %d\n", ft_is_sort(tab, length, &ft_more_than));
	printf("ft_is_sorted(.tabx.......) = %d\n", ft_is_sort(tabx, 13, &ft_more_than));
	printf("ft_is_sorted(.tabx.......) = %d\n", ft_is_sort(tabx, 13, &ft_less_than));
}
