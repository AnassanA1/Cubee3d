/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:39:38 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 13:08:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


static void print_map_line(void *content);
void print_raw_map(t_list *map)
{
    if (!map)
    {
        echo("Empty Map List !"); 
        return;  
    }
    ft_lstiter(map, print_map_line);
}

static void print_map_line(void *content)
{
    if (!is_map_config((char *)content))
    {
        char *colored = find_replace(MAPLINE, "$MAPLINE", (char *)content, 0);
        ft_putendl_fd(colored, 1);
        free (colored);
    }
    else
    {
        char *colored = find_replace(CONFIG, "$CONFIG", (char *)content, 0);
        ft_putendl_fd(colored, 1);
        free (colored);
    }
}


void echo(char *message)
{
    message = find_replace(ECHO_MSG, "$message", message, 0);
    ft_putstr_fd(message, 1);
    free(message);
}
void debug(char *lvl, char *message)
{
    message = find_replace(DEBUG_MSG, "$message", lvl, 0);
    printf("%s\n", message);
    ft_putstr_fd(message, 1);
    free(message);
    free(message);
}

void texture_info(t_texture *texture)
{
    printf("TYPE  : \033[0;36m%s\033[0m \n", texture->type == SOLID ? "COLOR" : "IMAGE");
    printf("PATH  : \033[0;36m%s\033[0m \n", texture->path);
    printf("COLOR : \033[0;36m%u\033[0m \n", texture->rgba);
    printf("ARGB  : \033[0;36mrgba(%d,%d,%d,%d)\033[0m \n", (texture->rgba >> 24) & 0xFF, (texture->rgba >> 16) & 0xFF, texture->rgba >> 8 & 0xFF, texture->rgba & 0xFF);
}

void print_map_grid(t_grid grid)
{
    size_t idx;
    
    idx = 0;
    if (!grid || !*grid)
    {
        echo("Empty Map !");
        return ;
    }
    while (grid[idx])
    {
        print_map_line(grid[idx]);
        idx++;
    }
}

void config_info(t_game *ref)
{
    echo("NORTH TEXTURE INFO :");
    texture_info(&ref->textures.north_txt);
    echo("SOUTH TEXTURE INFO :");
    texture_info(&ref->textures.south_txt);
    echo("EAST TEXTURE INFO :");
    texture_info(&ref->textures.east_txt);
    echo("WEST TEXTURE INFO :");
    texture_info(&ref->textures.west_txt);
    echo("SKY TEXTURE INFO :");
    texture_info(&ref->textures.sky_txt);
    echo("FLOOR TEXTURE INFO :");
    texture_info(&ref->textures.floor_txt);
    echo("GRID MAP INFO :");
    print_map_grid(ref->map.map2d);
}
