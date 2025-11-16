/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:39:38 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 17:11:26 by msidry           ###   ########.fr       */
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
    if (!isMapConfig((char *)content))
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

void texture_info(t_texture *texture)
{
    printf("TYPE : %s\n", texture->type == SOLID ? "COLOR" : "IMAGE");
    printf("PATH : %s\n", texture->path);
    printf("ARGB : (%d,%d,%d,%d) \n", texture->argb >> 24 & 0xFF, texture->argb >> 16 & 0xFF, texture->argb >> 8 & 0xFF, texture->argb & 0xFF);
}
