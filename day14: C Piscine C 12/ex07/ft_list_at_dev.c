/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:30:36 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 16:30:36 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == 0)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	return (ft_list_at(begin_list->next, nbr - 1));
}

int		main(void)
{
	int		index;
	int		*malloced_index;
	t_list	*list;

	index = 1;
	list = ft_create_elem(0);
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = index;
		ft_list_push_back(&list, (void *)malloced_index);
		index++;
	}
	index = 1;
	while (index < 10)
	{
		printf("data at index %d is %d\n", index,
			*((int *)ft_list_at(list, index)->data));
		index++;
	}
}
