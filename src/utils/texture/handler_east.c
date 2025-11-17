/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_east.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:29:20 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 11:38:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_east_texture(t_error *err, t_gametxt *textures, char *line)
{
    echo("FROM EAST HANDLER !");
    texture_format_handler(err, &textures->east_txt, line);
    texture_info(&textures->east_txt);
}
