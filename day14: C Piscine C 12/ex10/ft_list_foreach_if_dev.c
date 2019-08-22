/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:38:24 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 17:38:24 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>
#include <stdio.h>

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
				void *data_ref, int (*cmp)())
{
	if (begin_list == 0)
		return ;
	if ((*cmp)(begin_list->data, data_ref) == 0)
		(*f)(begin_list->data);
	ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
}

void	print_element(void *element)
{
	printf("element:: %d\n", *((int *)element));
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
	ft_list_foreach_if(list, &print_element, modulo, &compare_modulo);
}
