/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:47:43 by msidry            #+#    #+#             */
/*   Updated: 2026/02/12 11:28:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void init_map(t_game *ref);
static void set_height_width(t_map *map);

void map_handler(t_game *ref)
{
    if (!isAllOk(ref))
        return ;
    init_map(ref);
    map_validator(ref);
}



static void init_map(t_game *ref)
{
    char    **raw2d;

    raw2d = serializer(ref->configfile.maplist);
    ref->map.map2d = trim_tail_empty(raw2d);
    if (!ref->map.map2d)
    {
        setError(&ref->error, EMPTY_MAP);
        setStat(&ref->error, EXIT_FAILURE);
        nullarr2d((void ***)&raw2d, str2dlen(raw2d));
        return ;

    }
    nullarr2d((void ***)&raw2d, str2dlen(raw2d));
    set_height_width(&ref->map);
}


static void set_height_width(t_map *map)
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
        map->height++;
    }
}
