/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_texture_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:37:43 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 10:47:52 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void path_handler(t_error *error, t_texture *texture, char *path)
{
    (void)error;
    texture->type = IMAGE;
    nullstr(&texture->path);
    texture->path = ft_strtrim(path, "\t \r\b\n\v");
    texture->rgba = ~0;
    texture->isvalid = true;
}
