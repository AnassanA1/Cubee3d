/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_west.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:30:24 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 19:39:18 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_west_texture(t_error *err, t_gametxt *textures, char *line)
{
    
    echo("FROM WEST HANDLER !");
    texture_info(&textures->west_txt);
    texture_format_handler(err, &textures->west_txt, line);

}
