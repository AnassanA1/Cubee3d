/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:16:19 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 16:57:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void texture_handler(t_game *ref)
{
    t_list *list;
    char *line;

    if (!isAllOk(ref))
        return ;
    list = ref->scene.rawmap;
    while (list)
    {
        line = (char *)list->content;
        if (isMapConfig(line))
        {
            if (config_handler(&ref->error, &ref->textures, line))
                return;
        }
        list = list->next;
    }
}


int config_handler(t_error *error, t_gametxt *textures, char *line)
{
    static char     *identifiers[6];
    static callconfi callbacks[6] ;
    size_t idx;
    identifiers[0] = SOUTH;
    identifiers[1] = NORTH;
    identifiers[2] = EAST;
    identifiers[3] = WEST;
    identifiers[4] = SKY;
    identifiers[5] = FLOOR;
    callbacks[0] = set_south_texture;
    callbacks[1] = set_north_texture;
    callbacks[2] = set_east_texture;
    callbacks[3] = set_west_texture;
    callbacks[4] = set_sky_texture;
    callbacks[5] = set_floor_texture;
    idx = -1;
    while (++idx < 6)
    {
        if (!ft_strncmp(identifiers[idx], line, ft_strlen(identifiers[idx])))
        {
           callbacks[idx](error, textures, line);
           return (error->stat); 
        }
    }
    return (0);
}

