/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:33:05 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 11:22:23 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void config_handler(t_game *ref)
{
    if (!isAllOk(ref))
        return ;
    read_raw_config(ref);
    texture_handler(ref);
    map_handler(ref);
}
