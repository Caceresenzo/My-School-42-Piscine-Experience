/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:25:14 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/13 15:25:15 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

# include <stdbool.h>

# define BUFFER_SIZE 1024

# define MSG_ERR_NO_FILE "File name missing.\n"
# define MSG_ERR_TOO_MANY_ARGS "Too many arguments.\n"
# define MSG_ERR_CANNOT_READ "Cannot read file.\n"

# define IN 0
# define OUT 1
# define ERR 2

/*
** DISPLAY_FILE.c
*/
bool	display_file(char *path);

/*
** STRING_UTILS.c
*/
void	str_write(int fd, char *str);

#endif
