/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_south.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:30:13 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 12:48:04 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_south_texture(t_error *err, t_gametxt *textures, char *line)
{
    texture_format_handler(err, &textures->south_txt, line);
}
