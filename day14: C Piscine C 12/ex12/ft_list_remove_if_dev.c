/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:07:15 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 18:07:15 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
				void (*free_fct)(void *))
{
	t_list	*removed;

	if (begin_list == 0 || (*begin_list)->next == 0)
		return ;
	if ((*cmp)((*begin_list)->next->data, data_ref) == 0)
	{
		removed = (*begin_list)->next;
		(*begin_list)->next = removed->next;
		(*free_fct)(removed->data);
		free(removed);
	}
	ft_list_remove_if(&(*begin_list)->next, data_ref, cmp, free_fct);
}

void	delete_element(void *element)
{
	printf("element:: %d\n", *((int *)element));
	free(element);
}

int		compare_modulo(void *data, void *data_ref)
{
	return (*((int *)data) % *((int *)data_ref));
}

int		main(void)
{
	int		*index;
	int		*modulo;
	int		*malloced_index;
	t_list	*list;

	index = malloc(sizeof(int));
	*index = 0;
	list = ft_create_elem(index);
	while ((*index += 1) < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = *index;
		ft_list_push_back(&list, (void *)malloced_index);
	}
	modulo = malloc(sizeof(int));
	*modulo = 2;
	ft_list_remove_if(&list, modulo, &compare_modulo, &delete_element);
	list = list->next;
	*index = 0;
	while (list)
	{
		printf("list[%d] = %d\n", *index, *((int *)list->data));
		list = list->next;
		*index += 1;
	}
}
