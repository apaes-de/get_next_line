/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaes-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:55:34 by apaes-de          #+#    #+#             */
/*   Updated: 2022/01/05 18:55:36 by apaes-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_data
{
	char	*temp;
	int		index;
	int		index_buff;
	int		index_resto;

}	t_data;

char	*get_next_line(int fd);
int		check_buff(char *buffer, int *line_size);
char	*create_line(char *line, char *buffer, int line_size);
int		get_size(char *buffer);

#endif
