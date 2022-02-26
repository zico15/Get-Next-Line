/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:07:45 by edos-san          #+#    #+#             */
/*   Updated: 2021/12/09 18:20:44 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	f[BUFFER_SIZE + 1];
	t_line		d;

	d.line = NULL;
	d.size_buffer = 0;
	d.index = 1;
	while (fd >= 0 && f[d.size_buffer])
		d.size_buffer++;
	d.size_line = 0;
	while (fd >= 0 && d.index > 0)
	{
		if (!f[0] || !d.size_buffer)
			d.size_buffer = read(fd, f, BUFFER_SIZE);
		d.index = d.size_buffer;
		if (d.size_buffer > 0)
		{
			d.size_buffer = 0;
			while (f[d.size_buffer] && f[d.size_buffer] != '\n')
				d.size_buffer++;
			d.index = (d.index == d.size_buffer);
			d.size_buffer += f[d.size_buffer] == '\n';
			d.line = get_line(d.line, f, d.size_buffer, &d.size_line);
		}
	}
	return (d.line);
}
