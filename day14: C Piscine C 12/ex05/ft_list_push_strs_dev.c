/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:00:46 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 15:00:46 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;

	if (size == 0)
		return (0);
	list = ft_create_elem((void *)strs[size - 1]);
	list->next = ft_list_push_strs(size - 1, strs);
	return (list);
}

int		main(int argc, char **argv)
{
	int		index;
	t_list	*current;

	index = 0;
	current = ft_list_push_strs(argc, argv);
	while (current != 0)
	{
		printf("list[%d] = $%s$\n", index++, (char *)current->data);
		current = current->next;
	}
}
