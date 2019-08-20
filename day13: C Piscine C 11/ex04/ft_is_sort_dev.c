/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:36:30 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/16 15:36:30 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (length < 2)
		return (1);
	return ((*f)(tab[0], tab[1]) && ft_is_sort(tab + 1, length - 1, f));
}

int	ft_is_less_than(int a, int b)
{
	return (a < b);
}

int	ft_is_more_than(int a, int b)
{
	return (a > b);
}

int	main(void)
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
	printf("ft_is_sorted(1.........10) = %d\n", ft_is_sort(tab, length, &ft_is_less_than));
	index = 0;
	while (index < length)
	{
		tab[length - 1 - index] = index;
		index++;
	}
	printf("ft_is_sorted(10.........1) = %d\n", ft_is_sort(tab, length, &ft_is_more_than));
	tab[5] = 100;
	printf("ft_is_sorted(10...100...1) = %d\n", ft_is_sort(tab, length, &ft_is_more_than));
	tab[5] = 4;
	tab[9] = 100;
	printf("ft_is_sorted(10.....1.100) = %d\n", ft_is_sort(tab, length, &ft_is_more_than));
}
