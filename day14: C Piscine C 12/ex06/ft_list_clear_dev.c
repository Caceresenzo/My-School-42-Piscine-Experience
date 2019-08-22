/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:15:11 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 15:15:11 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list->next != 0)
		ft_list_clear(begin_list->next, free_fct);
	(*free_fct)(begin_list->data);
	free(begin_list);
}

void	print_element(void *element)
{
	printf("element:: %d\n", *((int *)element));
	free(element);
}

int		main(void)
{
	int		*index;
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
	ft_list_clear(list, &print_element);
}
