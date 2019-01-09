/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:03:31 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/09 14:29:35 by jsegueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int fd;
	int res;
	char *line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
//	printf("apres open");
	if (fd == -1)
		return (-1);
	line = ft_strnew(BUFF_SIZE);
//	printf("apres strnew");
	if (line == NULL)
		return (-2);
	res = get_next_line(fd, &line);
//	printf("apres get_next_line");
//	ft_putstr("tout va bien ici");
	if (res == -1)
		return (-1);
	while (res > 0)
	{
	//	ft_putstr(line);
	//	ft_putchar('\n');
		res = get_next_line(fd, &line);
	}
	return (0);
}
