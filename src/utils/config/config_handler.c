/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:33:05 by msidry            #+#    #+#             */
/*   Updated: 2026/02/12 12:46:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


static void read_config(t_game *ref, char *file);
static void read_map(t_game *ref, char *file);
static bool match_conf(char *rawline);
void config_handler(t_game *ref, char *file)
{
    read_config(ref, file);
    read_map(ref, file);
    texture_handler(ref);
    map_handler(ref);
}



static void read_config(t_game *ref, char *file)
{
    char    *rawline;
    int fd;
    t_list *newnode;

    fd = open(file, O_RDONLY);
    while ((rawline = get_next_line(fd)))
    {
        if (match_conf(rawline))
        {
            newnode = ft_lstnew(ft_strtrim(rawline, SPACES));
            ft_lstadd_back(&ref->configfile.conflist, newnode);
        }
        else if (!contain_only(rawline, SPACES))
        {
            free(rawline);
            return;
        }
        free(rawline);
    }
    close(fd);
}


static void read_map(t_game *ref, char *file)
{
    char    *rawline;
    int     fd;
    t_list *newnode;

    fd = open(file, O_RDONLY);
    while ((rawline = get_next_line(fd)))
    {
        if (match_conf(rawline) || contain_only(rawline, SPACES))
            free(rawline);
        else
        {
            newnode = ft_lstnew(ft_strtrim(rawline, "\n"));
            ft_lstadd_back(&ref->configfile.maplist, newnode);
            free(rawline);
            break;
        }
    }
    while ((rawline = get_next_line(fd)))
    {
        newnode = ft_lstnew(ft_strtrim(rawline, "\n"));
            ft_lstadd_back(&ref->configfile.maplist, newnode);
        free(rawline);
    }
    close(fd);
}


static bool match_conf(char *rawline)
{
    static char *identifiers[7];
    int         i;

    i = -1;
    while (is_space(*rawline))
        rawline++;
    identifiers[0] = NORTH;
    identifiers[1] = SOUTH;
    identifiers[2] = WEST;
    identifiers[3] = EAST;
    identifiers[4] = SKY;
    identifiers[5] = FLOOR;
    identifiers[6] = NULL;
    while (identifiers[++i])
    {
        if (!ft_strncmp(identifiers[i], rawline, ft_strlen(identifiers[i])))
            return (true);
    }
    
    return (false);
}