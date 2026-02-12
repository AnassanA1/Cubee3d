/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:10:10 by msidry            #+#    #+#             */
/*   Updated: 2026/02/12 11:34:41 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void clean_scene(t_scene *scene);
static void clean_error(t_error *error);
static void clean_textures(t_textures *textures);
static void clean_map(t_map *map);
static void clear_config(t_confile *conf);


void game_destroy(t_game *ref)
{
    // TODO: release resources !
    clear_config(&ref->configfile);
    clean_scene(&ref->scene);
    clean_error(&ref->error);
    clean_textures(&ref->textures);
    clean_map(&ref->map);
}

static void clean_scene(t_scene *scene)
{
    if (scene->fd > -1)
        close(scene->fd);
    ft_lstclear(&scene->rawmap, free);
}
static void clean_error(t_error *error)
{
    if (error)
    {
        free(error->message);
        error->stat = 0;
    }
}

static void clean_textures(t_textures *textures)
{
    if (textures)
    {
        if (textures->south_txt.type == IMAGE)
            nullstr(&textures->south_txt.texture.img_texture.path);
        if (textures->north_txt.type == IMAGE)
            nullstr(&textures->north_txt.texture.img_texture.path);
        if (textures->east_txt.type == IMAGE)
            nullstr(&textures->east_txt.texture.img_texture.path);
        if (textures->west_txt.type == IMAGE)
            nullstr(&textures->west_txt.texture.img_texture.path);
        if (textures->floor_txt.type == IMAGE)
            nullstr(&textures->floor_txt.texture.img_texture.path);
        if (textures->sky_txt.type == IMAGE)
            nullstr(&textures->sky_txt.texture.img_texture.path);
    }
}

static void clean_map(t_map *map)
{
    map->height = 0;
    map->width = 0;
    nullarr2d((void ***)&map->map2d, str2dlen(map->map2d));
}

static void clear_config(t_confile *conf)
{
    ft_lstclear(&conf->conflist, free);
    conf->conflist = NULL;
    ft_lstclear(&conf->maplist, free);
    conf->maplist = NULL;
}