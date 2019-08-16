/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:34:59 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/15 13:34:59 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITE_NUMBER_H
# define FT_WRITE_NUMBER_H

# define MAX_BUFFER_SIZE 14

void	ft_buffer_number(int number, int radix, int buffer[], int index);

void	ft_write_number(unsigned int number, int radix, int char_count);

void	ft_write_safe_char(char *c);

#endif
