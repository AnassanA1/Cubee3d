/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:53:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 11:55:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static int map_start(char *line);
void read_raw_config(t_game *ref)
{
    char *rawline;
    char *pureline;

    while (true)
    {
        rawline = get_next_line(ref->scene.fd);
        if (!rawline)
            break;
        pureline = ft_strtrim(rawline, "\n \v\t\r\b");
        if (map_start(pureline))
            ft_lstadd_back(&ref->scene.rawmap, ft_lstnew(pureline));
        else
            free(pureline);
        free(rawline);
    }
    close(ref->scene.fd);
    ref->scene.fd = -1;
    if (!ref->scene.rawmap)
    {
        setError(&ref->error, EMPTY_CONF);
        setStat(&ref->error, 1);
    }
}
static int map_start(char *line)
{
    static int inMap;
    if (inMap)
        return (1);
    if (!*line)
        return (0);
    if (!is_map_config(line))
        inMap = 1; 
    return (1);
}
