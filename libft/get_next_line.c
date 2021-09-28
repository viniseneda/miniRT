/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:31:45 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/23 18:25:30 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*append(char *current_string, char *rest_of_line)
{
	size_t	total_size;
	char	*return_string;
	char	*string_iterator;

	total_size = ft_strlen(current_string) + ft_strlen(rest_of_line);
	return_string = malloc(sizeof(char) * (total_size + 1));
	if (return_string == NULL)
	{
		free(current_string);
		free(rest_of_line);
		return (NULL);
	}
	ft_memset(return_string, 0, total_size + 1);
	string_iterator = copy(return_string, current_string);
	copy(string_iterator, rest_of_line);
	free(current_string);
	free(rest_of_line);
	return (return_string);
}

static char	*read_buffer(ssize_t cursor, int fd, ssize_t *status)
{
	static char	buffer[BUFFER_SIZE + 1];

	if (cursor == 0)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
		*status = read(fd, buffer, BUFFER_SIZE);
		if (*status < 0)
			return (NULL);
	}
	return (buffer);
}

void	check_flag(ssize_t *status, ssize_t *cursor, int *flag)
{
	if ((*status == 0) || (*cursor > (ssize_t)(*status)))
	{
		*flag = 0;
		*cursor = 0;
	}
}

static char	*get(int fd, ssize_t *status, int *flag)
{
	static ssize_t	cursor;
	t_rec_vars		v;

	v.beg = cursor;
	v.buffer = read_buffer(cursor, fd, status);
	if (v.buffer == NULL)
		return (NULL);
	while (cursor < BUFFER_SIZE)
	{
		if ((*(v.buffer + cursor) == '\n') || (*(v.buffer + cursor) == '\0'))
		{
			cursor++;
			v.rest_of_line = ft_substr(v.buffer, v.beg, cursor - v.beg - 1);
			check_flag(status, &cursor, flag);
			return (v.rest_of_line);
		}
		cursor++;
	}
	v.current_string = ft_substr(v.buffer, v.beg, cursor - v.beg);
	cursor = 0;
	v.rest_of_line = get(fd, status, flag);
	if ((v.rest_of_line == NULL) || (v.current_string == NULL))
		return (NULL);
	return (append(v.current_string, v.rest_of_line));
}

int	get_next_line(int fd, char **line)
{
	int				flag;
	static ssize_t	status;

	flag = 1;
	if ((BUFFER_SIZE <= 0) || (fd < 0) || (line == NULL))
		return (-1);
	*line = get(fd, &status, &flag);
	if ((*line == NULL) || (status < 0))
		return (-1);
	return (flag);
}
