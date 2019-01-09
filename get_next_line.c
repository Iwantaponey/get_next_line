/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:03:19 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/09 18:14:41 by jsegueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *overflow[BUFF_SIZE], char **line)
{
	int i;
	int j;

	if (*overflow == NULL)
		return (-2);
	i = 0;
	j = 0;
	while ((*overflow)[i])
	{
		if ((*overflow)[i] == '\n')
		{
			*line = ft_strsub(*overflow, 0, i);
			*overflow = ft_strsub(*overflow, i, ft_strlen(*overflow));
			return (1);
		}
		++i;
	}
	*line = ft_strdup(*overflow);
	*overflow = ft_strdup("");
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char overflow[BUFF_SIZE] = "";
	int			res;
	int			check;

	if (*line == NULL || fd == -1)
		return (-1);
	res = read(fd, overflow, BUFF_SIZE);
	if (res < 0)
		return (-1);
	check = check_newline((char **)&overflow, line);
	return (res > 0);
}
