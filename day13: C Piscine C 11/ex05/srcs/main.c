/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:15:37 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/18 16:15:37 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_boolean.h"
#include "ft_str.h"
#include "ft_number.h"
#include "ft_to.h"
#include "ft_io.h"

#define INVALID -1

char	ft_find_operator(char *str)
{
	if (str[0] == '\0' || str[1] != '\0')
		return (INVALID);
	return (str[0]);
}

t_bool	ft_validate_operation(int b, char operator)
{
	if (operator == '/' && b == 0)
	{
		ft_str_write("Stop : division by zero\n");
		return (false);
	}
	if (operator == '%' && b == 0)
	{
		ft_str_write("Stop : modulo by zero\n");
		return (false);
	}
	return (true);
}

void	ft_do_operation(int a, int b, char operator)
{
	static char	operators[5] = { '+', '-', '/', '*', '%' };
	static int	(*operations[5])(int, int) = {
			&ft_operation_add,
			&ft_operation_minus,
			&ft_operation_devide,
			&ft_operation_multiply,
			&ft_operation_modulo
	};
	int			result;
	int			index;

	result = 0;
	index = 0;
	while (index < 5)
	{
		if (operator == operators[index])
		{
			result = (operations[index])(a, b);
			break ;
		}
		index++;
	}
	ft_number_write(result);
	ft_str_write("\n");
}

int		main(int argc, char **argv)
{
	int		a;
	int		b;
	char	operator;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		operator = ft_find_operator(argv[2]);
		if (ft_validate_operation(b, operator))
			ft_do_operation(a, b, operator);
	}
}
