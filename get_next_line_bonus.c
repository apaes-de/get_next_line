/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaes-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:56:52 by apaes-de          #+#    #+#             */
/*   Updated: 2022/01/26 21:56:54 by apaes-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE];
	char		*line;
	int			read_size;
	int			line_size;
	int			is_line;

	line = NULL;
	read_size = 0;
	line_size = 0;
	is_line = fd >= 0;
	while (fd >= 0 && is_line && fd < FOPEN_MAX)
	{
		if (!buffer[fd][0])
			read_size = read(fd, buffer[fd], BUFFER_SIZE);
		else
			read_size = get_size(buffer[fd]);
		if (read_size > 0)
		{
			is_line = check_buff(buffer[fd], &line_size);
			line = create_line(line, buffer[fd], line_size);
		}
		else
			is_line = 0;
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("ola", O_RDONLY);
	if (fd < 3 && fd != 0)
		return (-1);
	printf("FD: %d\n", fd);
	printf("1: (%s)", get_next_line(fd));
	printf("2: (%s)", get_next_line(fd));
	printf("3: (%s)", get_next_line(fd));
	printf("4: (%s)", get_next_line(fd));
	printf("5: (%s)", get_next_line(fd));
	printf("6: (%s)", get_next_line(fd));
	return (0);
}*/
