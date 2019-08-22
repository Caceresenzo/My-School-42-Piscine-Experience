/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:16:33 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/20 13:16:33 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	list->next = 0;
	list->data = data;
	return (list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_list;

	new_list = ft_create_elem(data);
	new_list->next = (*begin_list);
	*begin_list = new_list;
}

int		ft_list_size(t_list *begin_list)
{
	if (begin_list->next == 0)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list->next == 0)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;

	if (size == 0)
		return (0);
	list = ft_create_elem((void *)strs[size - 1]);
	list->next = ft_list_push_strs(size - 1, strs);
	return (list);
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list->next != 0)
		ft_list_clear(begin_list->next, free_fct);
	(*free_fct)(begin_list->data);
	free(begin_list);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == 0)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	return (ft_list_at(begin_list->next, nbr - 1));
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next;
	t_list	*previous;
	t_list	*current;

	if (*begin_list == 0)
		return ;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list == 0)
		return ;
	(*f)(begin_list->data);
	ft_list_foreach(begin_list->next, f);
}

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
				void *data_ref, int (*cmp)())
{
	if (begin_list == 0)
		return ;
	if ((*cmp)(begin_list->data, data_ref) == 0)
		(*f)(begin_list->data);
	ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
}

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == 0)
		return (NULL);
	if ((*cmp)(begin_list->data, data_ref) == 0)
		return (begin_list);
	return (ft_list_find(begin_list->next, data_ref, cmp));
}

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

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;
	t_list	*previous;

	current = *begin_list1;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	previous->next = begin_list2;
}
