/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:47:43 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 19:36:54 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void map_handler(t_game *ref)
{
    if (!isAllOk(ref))
        return ;
    read_raw_map(ref);
    texture_handler(ref);
}
