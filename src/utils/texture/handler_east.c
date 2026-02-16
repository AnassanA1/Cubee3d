/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_east.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:29:20 by msidry            #+#    #+#             */
/*   Updated: 2026/01/13 12:20:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	set_east_texture(t_error *err, t_textures *textures, char *line)
{
	static int	duplicate;
	char		*msg;

	if (err->stat)
		return ;
	texture_format_handler(err, &textures->east_txt, line);
	if (duplicate || textures->east_txt.type != IMAGE)
	{
		if (duplicate)
			msg = find_replace(ERROR_DUP, "$TXT", "east (EA) :", 0);
		else
			msg = find_replace(ERROR_ITXT, "$TXT", "east (EA) :", 0);
		setError(err, msg);
		setStat(err, EXIT_FAILURE);
		free(msg);
		return ;
	}
	duplicate = 1;
}
