/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_north.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:29:50 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 11:39:03 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_north_texture(t_error *err, t_gametxt *textures, char *line)
{
    echo("FROM NORTH HANDLER !");
    texture_format_handler(err, &textures->north_txt, line);
    texture_info(&textures->north_txt);
}
