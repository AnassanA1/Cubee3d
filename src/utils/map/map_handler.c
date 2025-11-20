/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:47:43 by msidry            #+#    #+#             */
/*   Updated: 2025/11/20 12:29:14 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void init_map(t_game *ref);
static void normaize_width(t_map *map);
static t_list *extract_map(t_list *rawmap);

void map_handler(t_game *ref)
{
    if (!isAllOk(ref))
        return ;
    init_map(ref);
    //map_validator(ref);
}



static void init_map(t_game *ref)
{
    t_list  *map;
    char    **raw2d;

    map = extract_map(ref->scene.rawmap);
    raw2d = serializer(map);
    ref->map.map2d = trim_tail_empty(raw2d);
    if (!ref->map.map2d)
    {
        setError(&ref->error, EMPTY_MAP);
        setStat(&ref->error, EXIT_FAILURE);
    }
    nullarr2d((void ***)&raw2d, str2dlen(raw2d));
    normaize_width(&ref->map);
}

static t_list *extract_map(t_list *rawmap)
{
    while (rawmap)
    {
        if (!is_map_config((char *)rawmap->content))
            return (rawmap);
        rawmap = rawmap->next;
    }
    return (NULL);
}

static void normaize_width(t_map *map)
{
    size_t idx;
    size_t len;

    idx = 0;
    while (map->map2d[idx])
    {
        len = ft_strlen(map->map2d[idx]);
        if (len > map->width)
            map->width = len;
        idx++;
    }
    idx = 0;
    while (map->map2d[idx])
    {
        map->map2d[idx] = normalize(map->map2d[idx], map->width + 1, ' ');
        idx++;
    }
}