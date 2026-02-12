/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:53:59 by msidry            #+#    #+#             */
/*   Updated: 2026/02/12 11:10:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static int map_start(char *line);
static void manage_line(t_scene *scene, char *rawline);

void read_raw_config(t_game *ref, char *file)
{
    char *rawline;
    int fd;

    fd = open(file, O_RDONLY);
    while (true)
    {
        rawline = get_next_line(fd);
        if (!rawline)
            break;
        manage_line(&ref->scene, rawline);
        free(rawline);
    }
    close(fd);
    fd = -1;
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
    if (!*line || *line == '\n')
        return (0);
    if (!is_map_config(line))
        inMap = 1; 
    return (1);
}

static void manage_line(t_scene *scene, char *rawline)
{
    char *newline;
    
    if (map_start(rawline))
    {
        newline = ft_strtrim(rawline, "\n");
        ft_lstadd_back(&scene->rawmap, ft_lstnew(newline));
        return;
    }
    newline = ft_strtrim(rawline, SPACES);
    if (newline && *newline)
    {
        ft_lstadd_back(&scene->rawmap, ft_lstnew(newline));
        return ;
    }
    nullstr(&newline);
}
