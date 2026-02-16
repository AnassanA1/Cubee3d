/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_format_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:44:01 by msidry            #+#    #+#             */
/*   Updated: 2026/01/12 10:13:02 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static char			*extract_format(char *line);
static callformat	mapper(char *format);

void	texture_format_handler(t_error *error, t_texture *target, char *line)
{
	char		*format;
	char		*msg;
	callformat	callback;

	format = extract_format(line + is_map_config(line));
	callback = mapper(format);
	if (!format || !callback)
	{
		msg = find_replace(ERROR_GENERAL, "$MSG", ERROR_FORMAT, 0);
		setError(error, msg);
		setStat(error, EXIT_FAILURE);
		free(msg);
		return ;
	}
	callback(error, target, format + 4);
	free(format);
}

static char	*extract_format(char *line)
{
	int	fd;

	if (!is_space(*line))
		return (NULL);
	while (*line && is_space(*line))
		line++;
	if (!*line)
		return (NULL);
	fd = open(line, O_RDONLY);
	if (fd > 0 && !close(fd))
		return (concat3("PATH", line, " ", 0));
	if (*line == '#')
		return (concat3("HEXA", line + 1, " ", 0));
	if (!ft_strncmp(line, "rgba", 4))
		return (concat3("RGBA", line + 4, " ", 0));
	return (find_replace("RGBA ($RGBA,255)", "$RGBA", line, 0));
}

static callformat	mapper(char *format)
{
	static callformat	callbacks[3];
	static char			*formats[3];
	int					idx;

	callbacks[0] = hexa_handler;
	callbacks[1] = rgba_handler;
	callbacks[2] = path_handler;
	formats[0] = HEXA;
	formats[1] = RGBA;
	formats[2] = PATH;
	idx = -1;
	while (++idx < 3)
	{
		if (ft_strlen(format) < 4)
			return (NULL);
		if (!ft_strncmp(format, formats[idx], 4))
			return (callbacks[idx]);
	}
	return (NULL);
}
