/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegueni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:00:00 by jsegueni          #+#    #+#             */
/*   Updated: 2019/01/09 17:57:24 by jsegueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 520
# endif

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdio.h>

int	get_next_line(const int fd, char **line);

#endif
