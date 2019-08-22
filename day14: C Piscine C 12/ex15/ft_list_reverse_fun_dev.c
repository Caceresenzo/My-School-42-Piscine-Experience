/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:45:58 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 16:45:58 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*next;
	t_list	*previous;
	t_list	*current;
	void	*previous_value;

	if (begin_list == 0)
		return ;
	previous_value = 0;
	current = begin_list;
	while (current != NULL)
	{
		next = current->next;
		if (next != 0)
			break ;
		previous_value = next->data;
		current->data = previous_value;
		printf("%p  previous = %d\n", previous_value, previous_value == 0 ? -1 : *((int *)previous_value));
		current = next;
	}
	begin_list->data = previous_value;
}

int		main(void)
{
	int		index;
	int		*malloced_index;
	//int		*data;
	t_list	*list;
	t_list	*current;

	index = 1;
	list = ft_create_elem(0);
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = index;
		ft_list_push_back(&list, (void *)malloced_index);
		printf("%p list[%d] = %d\n", malloced_index, index, *malloced_index);
		index++;
	}
	index = 1;
	ft_list_reverse_fun(list->next);
	printf("Reversed\n");
	current = list->next;
	while (index < 10)
	{
		//data = (int *)current->data;
		//printf("list[%d] = %d\n", index, data != 0 ? *data : -1);
		printf("list[%d] = %d\n", index, *((int *)current->data));
		index++;
		current = current->next;
	}
}
