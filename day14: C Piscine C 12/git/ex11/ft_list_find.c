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

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == 0)
		return (NULL);
	if ((*cmp)(begin_list->data, data_ref) == 0)
		return (begin_list);
	return (ft_list_find(begin_list->next, data_ref, cmp));
}
