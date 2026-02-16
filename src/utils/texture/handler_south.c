/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_south.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:30:13 by msidry            #+#    #+#             */
/*   Updated: 2026/01/13 12:20:48 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	set_south_texture(t_error *err, t_textures *textures, char *line)
{
	static int	duplicate;
	char		*msg;

	if (err->stat)
		return ;
	texture_format_handler(err, &textures->south_txt, line);
	if (duplicate || textures->south_txt.type != IMAGE)
	{
		if (duplicate)
			msg = find_replace(ERROR_DUP, "$TXT", "south (SO) :", 0);
		else
			msg = find_replace(ERROR_ITXT, "$TXT", "south (SO) :", 0);
		setError(err, msg);
		setStat(err, EXIT_FAILURE);
		free(msg);
		return ;
	}
	duplicate = 1;
}
