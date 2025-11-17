/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_format_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:44:01 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 16:36:39 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static char *extract_format(char *line);
void texture_format_handler(t_error * error, t_texture *target, char *line)
{
    char    *format;
    char    *msg;
    callformat callbacks[3] = {rgba_handler, rgba_handler, rgba_handler};
    char *formats[3]= {HEXA, RGBA, PATH};
    size_t idx;
    
    idx = -1;
    format = extract_format(line + isMapConfig(line));
    if (!format)
    {
        msg = find_replace(ERROR_GENERAL, "$MSG", ERROR_FORMAT, 0) ;
        setError(error, msg);
        setStat(error, EXIT_FAILURE);
        free(msg);
        return ;
    }
    while (++idx < 3)
    {
        if (!ft_strncmp(format, formats[idx], ft_strlen(formats[idx] - 1)))
        {
            callbacks[idx](error, target, format + ft_strlen(formats[idx]));
            break;
        }
    }

    free(format);
}

static char *extract_format(char *line)
{
    size_t idx;
    int fd;

    if (!is_space(*line))
        return (NULL);
    idx = 0;
    while (*line && is_space(*line))
        line++;
    if (!*line)
        return (NULL);
    fd = open(line, O_RDONLY);
    if (fd > 0 && !close(fd))
        return (concat3("path", line, " ", 2));
    if (*line == '#')
        return (concat3("hexa", line + 1, " ", 0));
    if (!ft_strncmp(line, "rgba", 4))
        return (concat3("rgba", line + 4, " ", 0));
    return (find_replace("rgba ($RGBA,255)", "$RGBA", line, 0));
}

