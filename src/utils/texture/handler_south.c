/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_south.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:30:13 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 16:05:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_south_texture(t_error *err, t_gametxt *textures, char *line)
{
     
    echo("FROM SOUTH HANDLER!");
    texture_format_handler(err, &textures->south_txt, line);
    texture_info(&textures->south_txt);

}
