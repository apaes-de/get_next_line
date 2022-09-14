/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaes-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:57:04 by apaes-de          #+#    #+#             */
/*   Updated: 2022/01/26 21:57:07 by apaes-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
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
