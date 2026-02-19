/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:10:10 by msidry            #+#    #+#             */
/*   Updated: 2026/02/19 11:05:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void clean_textures(t_container *ref);
static void clean_map(t_map *map);
static void clear_dataconfig(t_container *ref);

void game_destroy(t_container *ref)
{
    clear_dataconfig(ref);
    clean_map(&ref->map);
    clean_textures(ref);
}

static void clean_map(t_map *map)
{
    map->height = 0;
    map->width = 0;
    nullarr2d((void ***)&map->map2d, str2dlen(map->map2d));
}

static void clear_dataconfig(t_container *ref)
{
    ft_lstclear(&ref->datafile.config, free);
    ft_lstclear(&ref->datafile.map, free);
    ft_lstclear(&ref->datafile.rawdata, free);
}

static void clean_textures(t_container *ref)
{
    int idx;

    idx = 0;
    while (idx < 2)
    {
        nullstr(&ref->txt_solid[idx].key);
        nullstr(&ref->txt_solid[idx].value);
        idx++;
    }
    idx = 0;
    while (idx < 4)
    {
        nullstr(&ref->txt_images[idx].key);
        nullstr(&ref->txt_images[idx].value);
        ref->txt_images[idx].img = NULL;
        idx++;
    }
} 