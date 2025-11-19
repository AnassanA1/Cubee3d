/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:16:19 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 11:05:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


static void valid_textures(t_error *error, t_gametxt *textuers);
static int texture_config_handler(t_error *error, t_gametxt *txts, char *line);

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
        if (is_map_config(line))
        {
            if (texture_config_handler(&ref->error, &ref->textures, line))
                return;
        }
        list = list->next;
    }
    valid_textures(&ref->error, &ref->textures);
}


static int texture_config_handler(t_error *error, t_gametxt *txts, char *line)
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
           callbacks[idx](error, txts, line);
           return (error->stat); 
        }
    }
    return (0);
}


static void valid_textures(t_error *error, t_gametxt *textuers)
{
    char *unvalid;

    unvalid = NULL;
    if (!textuers->north_txt.isvalid)
        unvalid = "NORTH";
    else if (!textuers->south_txt.isvalid)
        unvalid = "NORTH";
    else if (!textuers->west_txt.isvalid)
        unvalid = "WEST";
    else if (!textuers->east_txt.isvalid)
        unvalid = "EAST";
    else if (!textuers->sky_txt.isvalid)
        unvalid = "SKY";
    else if (!textuers->floor_txt.isvalid)
        unvalid = "FLOOR";
    if (unvalid)
    {
        unvalid = find_replace(ERROR_TXT, "$MSG", unvalid, 0);
        setError(error, unvalid);
        setStat(error, EXIT_FAILURE);
        nullstr(&unvalid);
    }
}
