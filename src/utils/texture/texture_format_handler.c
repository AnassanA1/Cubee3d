/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_format_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:44:01 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 19:49:11 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static char *extract_format(char *line);
void texture_format_handler(t_error * error, t_texture *target, char *line)
{
    char    *format;
    char    *msg;
    

    format = extract_format(line + ft_strlen(SOUTH));
    if (!format)
    {
        msg = find_replace(ERROR_GENERAL, "$MSG", ERROR_FORMAT, 0) ;
        setError(error, msg);
        setStat(error, EXIT_FAILURE);
        free(msg);
        return ;
    }
    echo(format);
    free(format);
    (void)target;
}

static char *extract_format(char *line)
{
    size_t idx;
    int fd;

    if (!is_space(*line))
        return (NULL);
    echo (line);
    idx = 0;
    while (*line && is_space(*line))
        line++;
    if (!*line)
        return (NULL);
    if (*line == '#')
        return (concat3("hexa", line + 1, " ", 0));
    if (!ft_strncmp(line, "rgba", 4))
        return (concat3("rgba", line + 4, " ", 0));
    if (!ft_strncmp(line, "rgb", 3))
        return (concat3("rgba", ft_strjoin(line + 1, ",255"), " ", 2));
    fd = open(line, O_RDONLY);
    if (fd > 0)
    {
        close(fd);
        return (concat3("file", line, " ", 2));
    }
    return (find_replace("rgba ($RGBA)", "$RGBA", line, 0));
}
