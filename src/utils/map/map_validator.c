/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:54:25 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 17:01:44 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void normaize_width(t_map *map, unsigned char toapp);

void map_validator(t_container *ref)
{
    size_t  idx;

    idx = 0;
    one_direction(ref, ref->map.map2d);
    while (ref->map.map2d[idx])
    {
        empty_line(ref, ref->map.map2d[idx]);
        supported_line(ref, ref->map.map2d[idx]);
        idx++;
    }
    normaize_width(&ref->map, ' ');
    closed_map(ref, &ref->map);
    space_in_path(ref, &ref->map);
}


static void normaize_width(t_map *map, unsigned char toapp)
{
    size_t idx;

    idx = 0;
    while (map->map2d[idx])
    {
        map->map2d[idx] = normalize(map->map2d[idx], map->width + 1, toapp);
        idx++;
    }
}
