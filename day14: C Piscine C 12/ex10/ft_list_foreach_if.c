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

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
				void *data_ref, int (*cmp)())
{
	if (begin_list == 0)
		return ;
	if ((*cmp)(begin_list->data, data_ref) == 0)
		(*f)(begin_list->data);
	ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
}
