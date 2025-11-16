/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:53:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 15:27:58 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static int map_start(char *line);
void read_raw_map(t_game *ref)
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
        setError(&ref->error, EMPTY_MAP);
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
    if (!isMapConfig(line))
        inMap = 1; 
    return (1);
}
