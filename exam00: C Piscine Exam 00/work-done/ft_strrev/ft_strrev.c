/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 18:41:14 by exam              #+#    #+#             */
/*   Updated: 2019/08/02 18:51:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_length(char *str)
{
	int index;

	index = 0;
	while (str[index++] != '\0');
	return (index - 1);
}

char	*ft_strrev(char *str)
{
	int size;
	int index;
	char tmp;

	size = ft_str_length(str);
	index = 0;
	while (index != size / 2)
	{
		tmp = str[index];
		str[index] = str[size - 1 - index];
		str[size - 1 - index] = tmp;
		index++;
	}
	return (str);
}
