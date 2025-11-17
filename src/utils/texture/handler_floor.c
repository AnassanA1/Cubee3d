/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:29:36 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 11:38:58 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_floor_texture(t_error *err, t_gametxt *textures, char *line)
{

    echo("FROM FLOOR HANDLER !");
    texture_format_handler(err, &textures->floor_txt, line);
    texture_info(&textures->floor_txt);
}
