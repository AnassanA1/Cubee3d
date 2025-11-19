/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:27:08 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 10:40:06 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

int is_map_config(char *line)
{
    static char *identifiers[7];
    int i;

    if (!line)
        return (0);
    i = -1;
    identifiers[0] = NORTH;
    identifiers[1] = SOUTH;
    identifiers[2] = WEST;
    identifiers[3] = EAST;
    identifiers[4] = SKY;
    identifiers[5] = FLOOR;
    identifiers[6] = NULL;
    while (identifiers[++i])
    {
        if (!ft_strncmp(identifiers[i], line, ft_strlen(identifiers[i])))
            return (ft_strlen(identifiers[i]));
    }
    return (0);
}
