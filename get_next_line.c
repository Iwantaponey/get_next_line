/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:03:19 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/10 17:12:25 by jsegueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char **overflow, char **line)
{
	int i;
	int j;

	if (!(*overflow))
		return (-2);
	i = 0;
	j = 0;
	while ((*overflow)[i] && i < BUFF_SIZE)
	{
		if ((*overflow)[i] == '\n')
		{
			*line = ft_strjoin(*line, ft_strsub(*overflow, 0, i));
//			printf(">>> line = %s <<<\n", *line);
			*overflow = *overflow + i;
			return (1);
		}
		++i;
	}
	*line = ft_strjoin(*line, ft_strdup(*overflow));
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char *overflow = NULL;
	int			res;
	int			check;

	if (overflow == NULL)
	{
		if (!(overflow = ft_strnew(BUFF_SIZE)))
				return (-1);
	}
	else
		*line = overflow;
	if (fd == -1)
		return (-1);
	res = read(fd, overflow, BUFF_SIZE);
//	printf(">>>overflow = %s<<<\n", overflow);
	if (res < 0)
		return (-1);
	check = check_newline(&overflow, line);
	if (check < 0)
		return (-1);
	return (res > 0);
}
