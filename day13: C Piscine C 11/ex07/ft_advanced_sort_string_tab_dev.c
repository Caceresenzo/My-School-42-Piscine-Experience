/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:18:03 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/20 11:18:03 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		index;
	int		size;
	bool	swapped;

	size = 0;
	while (tab[size])
		size++;
	while (true)
	{
		index = 0;
		swapped = false;
		while (index < size - 1)
		{
			if ((*cmp)(tab[index], tab[index + 1]) > 0)
			{
				ft_swap(&tab[index], &tab[index + 1]);
				swapped = true;
			}
			index++;
		}
		if (!swapped)
			break ;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

int		main(void)
{
	int		index;
	char	**tab;

	tab = malloc(8 * sizeof(char *));
	tab[0] = strdup("hello");
	tab[1] = strdup("world");
	tab[2] = strdup("a");
	tab[3] = strdup("aa");
	tab[4] = strdup("ba");
	tab[5] = strdup("ab");
	tab[6] = strdup("z");
	tab[7] = 0;
	index = 0;
	while (tab[index])
	{
		printf("tab[%d] <@ %p> = $%s$\n", index, tab + index, tab[index]);
		index++;
	}
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	printf("\n");
	index = 0;
	while (tab[index])
	{
		printf("tab[%d] <@ %p> = $%s$\n", index, tab + index, tab[index]);
		index++;
	}
}
