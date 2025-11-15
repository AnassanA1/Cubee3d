/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:40:43 by msidry            #+#    #+#             */
/*   Updated: 2025/11/15 13:19:33 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_full_line(int fd, char *buffer);
static char	*ft_merge_buffers(char *oldbuffer, char *newbuffer);
static char	*ft_get_current_line(char *buffer);
static char	*ft_reset_leftover(char *buffer);

/**
* get_next_line - reads a line from file each time called .
* @fd: file discriptor represent an entry in sys wide open file tables .
* @return return a string line or NULL if failed .
*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	if (!ft_contain(buffer, '\n'))
		buffer = ft_read_full_line(fd, buffer);
	if (buffer == NULL || !buffer[0])
		return (free(buffer), buffer = NULL, NULL);
	line = ft_get_current_line(buffer);
	buffer = ft_reset_leftover(buffer);
	return (line);
}

/**
* ft_read_full_line - reads from file till EOF or finds '\n' in previous read.
* @fd: file discriptor represent an entry in sys wide open file tables.
* @buffer: heap memory include leftover of previouse reads.
* @return a string or null.
*/

static char	*ft_read_full_line(int fd, char *buffer)
{
	char	*newbuffer;
	int		readbytes;

	newbuffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!newbuffer)
		return (free(buffer), buffer = NULL, NULL);
	while (1)
	{
		readbytes = read(fd, newbuffer, BUFFER_SIZE);
		if (readbytes == 0)
			break ;
		if (readbytes == -1)
			return (free(buffer), free(newbuffer), buffer = NULL, NULL);
		newbuffer[readbytes] = '\0';
		buffer = ft_merge_buffers(buffer, newbuffer);
		if (!buffer)
			return (free(newbuffer), newbuffer = NULL, NULL);
		if (ft_contain(newbuffer, '\n'))
			break ;
	}
	free(newbuffer);
	return (buffer);
}

/**
* ft_merge_buffers - join what was read previousely with the new read.
* @oldbuffer: string of previouse read or leftover.
* @newread: new readed string .
* @return string 1 + string 2  joined or NULL,
*/

static char	*ft_merge_buffers(char *oldbuffer, char *newbuffer)
{
	int		i;
	char	*merged_buf;
	size_t	index;

	i = 0;
	if (!newbuffer || !newbuffer[i])
		return (oldbuffer);
	merged_buf = ft_calloc(ft_strlen(oldbuffer) + ft_strlen(newbuffer) + 1, 1);
	if (!merged_buf)
	{
		free(oldbuffer);
		oldbuffer = NULL;
		return (NULL);
	}
	index = ft_strlcpy(merged_buf, oldbuffer, ft_strlen(oldbuffer) + 1);
	ft_strlcpy(&merged_buf[index], newbuffer, ft_strlen(newbuffer) + 1);
	free(oldbuffer);
	oldbuffer = NULL;
	return (merged_buf);
}

/**
* ft_get_current_line -takes the full readed string and retrive till '\n'or'\0'
* @buffer: full line of previouse read(s),
* @return return string line.
*/

static char	*ft_get_current_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc((i + 1), 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1);
	return (line);
}

/**
* ft_reset_leftover - reset the old buffer to new one.
* @buffer: the leftover buffer.
* @return new buffer contain fron '\n' to '\0'.
*/

static char	*ft_reset_leftover(char *buffer)
{
	size_t	i;
	char	*newbuffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	newbuffer = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	if (!newbuffer)
		return (NULL);
	ft_strlcpy(newbuffer, &buffer[i], (ft_strlen(buffer) - i + 1));
	free (buffer);
	return (newbuffer);
}
