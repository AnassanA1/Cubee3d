/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sky.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:10:03 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 12:45:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_sky_texture(t_error *err, t_gametxt *textures, char *line)
{
    texture_format_handler(err, &textures->sky_txt, line);
}

