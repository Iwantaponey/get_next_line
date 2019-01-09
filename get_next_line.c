/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:03:19 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/09 12:30:11 by jsegueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char **line)
{
	int i;

	if (*line == NULL)
		return (-2);
	i = 0;
	while (*line[i])
	{
		if (*line[i] == '\n')
		{	
			*line[i] = '\0';
			return (1);
		}
		++i;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int res;
	int check;

	if (*line == NULL)
		return (-2);
	res = read(fd, *line, BUFF_SIZE);
	check = check_newline(line);
	if (res < 0)
		return (-1);
	return (res > 0);
}
