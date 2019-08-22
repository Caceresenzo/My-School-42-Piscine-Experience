/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:51:41 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 13:51:41 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_list;

	new_list = ft_create_elem(data);
	new_list->next = (*begin_list);
	*begin_list = new_list;
}

int		main(void)
{
	int		data;
	int		data2;
	t_list	*base_list;

	data = 10;
	data2 = 20;
	base_list = ft_create_elem((void *)&data);
	ft_list_push_front(&base_list, (void *)&data2);
	printf("list->next: %p\n", base_list->next);
	printf("list->data: %d\n", *((int *)(base_list->data)));
	printf("list->x->next: %p\n", base_list->next->next);
	printf("list->x->data: %d\n", *((int *)(base_list->next->data)));
}
