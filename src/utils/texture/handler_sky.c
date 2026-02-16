/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sky.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:10:03 by msidry            #+#    #+#             */
/*   Updated: 2026/01/13 12:20:46 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	set_sky_texture(t_error *err, t_textures *textures, char *line)
{
	static int	duplicate;
	char		*msg;

	if (err->stat)
		return ;
	texture_format_handler(err, &textures->sky_txt, line);
	if (duplicate || textures->sky_txt.type != SOLID)
	{
		if (duplicate)
			msg = find_replace(ERROR_DUP, "$TXT", "sky (C) :", 0);
		else
			msg = find_replace(ERROR_CTXT, "$TXT", "sky (C) :", 0);
		setError(err, msg);
		setStat(err, EXIT_FAILURE);
		free(msg);
		return ;
	}
	duplicate = 1;
}
