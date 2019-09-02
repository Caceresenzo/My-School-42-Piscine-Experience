/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:51:22 by exam              #+#    #+#             */
/*   Updated: 2019/08/23 10:51:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_char(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strrev(char *str)
{
	int		index;
	int		size;

	size = 0;
	while (str[size])
		size++;
	index = 0;
	while (index < size / 2)
	{
		ft_swap_char(&str[index], &str[size - 1 - index]);
		index++;
	}
	return (str);
}
