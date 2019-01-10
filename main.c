/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:03:31 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/10 12:31:13 by jsegueni         ###   ########.fr       */
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
	res = get_next_line(fd, &line);
	if (res == -1)
		return (-1);
	while (res > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		res = get_next_line(fd, &line);
	}
	return (0);
}
