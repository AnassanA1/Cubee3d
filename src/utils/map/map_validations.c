/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:18:01 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 17:01:40 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"



void empty_line(t_container *ref, char *line)
{
    char *err;

    if (!*line || contain_only(line, SPACES) )
    {
        err = find_replace(ERROR_GENERAL, "$MSG", BAD_E_LINE, 0);
        ft_putstr_fd(err, STDERR_FILENO);
        game_destroy(ref);
        nullstr(&err);
        exit(EXIT_FAILURE);
    }
}

void supported_line(t_container *ref, char *line)
{
    char *err;
    if (!contain_only(line, MAPSET))
    {
        err = find_replace(ERROR_GENERAL, "$MSG", BAD_C_LINE, 0);
        ft_putstr_fd(err, STDERR_FILENO);
        game_destroy(ref);
        nullstr(&err);
        exit(EXIT_FAILURE);
    }
}



void one_direction(t_container *ref, char **arr)
{
    size_t y;
    size_t x;
    size_t count;
    char *err;

    y = -1;
    count = 0;
    while (arr && arr[++y])
    {
        x = -1;
        while (arr[y][++x])
        {
            if (match_count("NEWS", arr[y][x]))
                count++;
        }
    }
    if (count == 1)
        return;
    err = find_replace(ERROR_GENERAL, "$MSG", BAD_D_LINE, 0);
    ft_putstr_fd(err, STDERR_FILENO);
    game_destroy(ref);
    nullstr(&err);
    exit(EXIT_FAILURE);
}

void closed_map(t_container *ref, t_map *map)
{
    t_queue *queue;
    size_t x;
    size_t y;

    y = -1;
    queue = NULL;
    while (map->map2d[++y])
    {
        x = -1;
        while (map->map2d[y][++x])
        {
            if (x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
                q_push(&queue, q_create(map->map2d[y][x], x, y));
        }
    }
    if (is_closed_bff(map, &queue))
        return;
    ft_putstr_fd(BAD_C_MAP, STDERR_FILENO);
    game_destroy(ref);
    q_empty(&queue);
    exit(EXIT_FAILURE);
}



void space_in_path(t_container *ref, t_map *map)
{
    t_queue *queue;
    size_t x;
    size_t y;
    bool isfound;
    
    queue = NULL;
    y = -1;
    isfound = 0;
    while (map->map2d[++y] && !isfound)
    {
        x = -1;
        while (map->map2d[y][++x])
        {
            if (ft_strchr("NEWS", map->map2d[y][x]))
                q_push(&queue, q_create(map->map2d[y][x], x, y));
        }
    }
    if (is_nospace_bff(map, &queue))
        return ;
    ft_putstr_fd(BAD_P_MAP, STDERR_FILENO);
    game_destroy(ref);
    q_empty(&queue);
    exit(EXIT_FAILURE);
}
