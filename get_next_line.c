/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:03:19 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/09 13:58:11 by jsegueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char **line, char *overflow[BUFF_SIZE])
{
	int i;
	int j;

	if (*line == NULL)
		return (-2);
	i = 0;
	j = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
		{	
			(*line)[i] = '\0';
			++i;
			while ((*line)[i] && j < BUFF_SIZE)
			{
				(*overflow)[j] = (*line)[i];
				++i;
				++j;
			}
			return (1);
		}
		++i;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char overflow[BUFF_SIZE] = ""; 
	int res;
	int check;

	if (*line == NULL)
		return (-2);
	res = read(fd, *line, BUFF_SIZE);
	check = check_newline(line, (char**)&overflow);
	if (res < 0)
		return (-1);
	return (res > 0);
}
