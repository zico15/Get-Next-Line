/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:47:32 by edos-san          #+#    #+#             */
/*   Updated: 2021/12/04 14:55:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<unistd.h>
# include	<stdlib.h>
# include   <stdio.h>
# include	<stdlib.h>
# include	<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   45
# endif

typedef struct s_line
{
	char	*line;
	long	size_line;
	long	index;
	long	size_buffer;
	long	size_read;
}	t_line;

char	*get_line(char *line, char *buffer, long size_buffer, long *size_line);
char	*get_next_line(int fd);

#endif
