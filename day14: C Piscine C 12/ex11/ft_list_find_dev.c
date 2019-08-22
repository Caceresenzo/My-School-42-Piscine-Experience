/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:38:24 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 17:38:24 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == 0)
		return (NULL);
	if ((*cmp)(begin_list->data, data_ref) == 0)
		return (begin_list);
	return (ft_list_find(begin_list->next, data_ref, cmp));
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
	t_list	*found_element;

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
	found_element = ft_list_find(list->next, modulo, &compare_modulo);
	printf("found -> %d\n", *((int *)found_element->data));
}
