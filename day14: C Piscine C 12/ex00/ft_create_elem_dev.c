/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:16:33 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/20 13:16:33 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	list->next = 0;
	list->data = data;
	return (list);
}

int		main(void)
{
	int		data;
	t_list	*list;

	data = 10;
	list = ft_create_elem((void *)&data);
	printf("list->next: %p\n", list->next);
	printf("list->data: %d\n", *((int *)(list->data)));
}
