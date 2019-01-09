/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:03:19 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/09 14:39:23 by jsegueni         ###   ########.fr       */
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
			(*overflow) = (*line + i);
		//	ft_putstr(*line);
		//	ft_putchar('\n');
		//	ft_putstr(*overflow);
			return (1);
		}
		++i;
	}
//	ft_putstr(*line);
	*overflow = "";
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
	if (res < 0)
		return (-1);
	check = check_newline(line, (char**)&overflow);
//	if (check == 1)		
	return (res > 0);
}
