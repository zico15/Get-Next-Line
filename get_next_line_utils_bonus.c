/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:32:45 by edos-san          #+#    #+#             */
/*   Updated: 2021/12/13 18:07:03 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *line, char *buffer, long size_buffer, long *size_line)
{
	t_line	data;

	data.size_line = -1;
	data.index = -1;
	data.size_buffer = -1;
	data.line = line;
	*size_line += size_buffer;
	line = malloc(*size_line + 1 * sizeof(char));
	if (line)
	{
		line[*size_line] = 0;
		while (data.line && data.line[++data.size_line])
			line[++data.index] = data.line[data.size_line];
		data.size_line = -1;
		while (buffer && buffer[++data.size_line])
		{
			if (data.size_line < size_buffer)
				line[++data.index] = buffer[data.size_line];
			else
				buffer[++data.size_buffer] = buffer[data.size_line];
			buffer[data.size_line] = 0;
		}
	}
	free(data.line);
	return (line);
}
