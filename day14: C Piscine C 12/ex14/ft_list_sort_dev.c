/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:51:12 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 18:51:13 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "ft_list.h"

#include <stdio.h>

void	ft_swap_void(void **a, void **b)
{
	void *c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*end;
	bool	swapped;

	if (*begin_list == 0)
		return ;
	swapped = true;
	end = 0;
	while (swapped)
	{
		swapped = false;
		current = *begin_list;
		while (current->next != end)
		{
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				ft_swap_void(&(current->data), &(current->next->data));
				swapped = true;
			}
			current = current->next;
		}
		end = current;
	}
}

int		less_than(void *a, void *b)
{
	return ((*(int *)a) > (*(int *)b));
}

int		main(void)
{
	int		index;
	int		*malloced_index;
	t_list	*list;
	t_list	*current;

	index = 1;
	list = ft_create_elem(0);
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = 9 - index;
		ft_list_push_back(&list, (void *)malloced_index);
		printf("list[%d] = %d\n", index, *malloced_index);
		index++;
	}
	index = 1;
	ft_list_sort(&(list->next), &less_than);
	printf("Sorted\n");
	current = list->next;
	while (index < 10)
	{
		printf("list[%d] = %d\n", index, *((int *)current->data));
		index++;
		current = current->next;
	}
}
