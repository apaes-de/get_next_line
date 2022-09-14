/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaes-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:53:33 by apaes-de          #+#    #+#             */
/*   Updated: 2022/01/05 18:53:36 by apaes-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_size(char *buffer)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (i == 0)
				i++;
			return (i);
		}
		i++;
	}
	return (i);
}

int	check_buff(char *buffer, int *line_size)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
		{
			*line_size += (i + 1);
			return (0);
		}
		i++;
	}
	*line_size += i;
	return (buffer[i] != '\n');
}

char	*create_line(char *line, char *buffer, int line_size)
{
	t_data	data;

	data.index = 0;
	data.index_buff = 0;
	data.index_resto = -1;
	data.temp = line;
	line = malloc(line_size + 1 * sizeof(char));
	line[line_size] = 0;
	while (data.temp != 0 && data.temp[data.index])
		line[data.index++] = data.temp[data.index];
	while (buffer != 0 && buffer[data.index_buff])
	{
		if (data.index_resto < 0)
		{
			line[data.index++] = buffer[data.index_buff];
			if (buffer[data.index_buff] == '\n')
				data.index_resto++;
		}
		else
			buffer[data.index_resto++] = buffer[data.index_buff];
		buffer[data.index_buff++] = 0;
	}
	if (data.temp && *data.temp)
		free(data.temp);
	return (line);
}
