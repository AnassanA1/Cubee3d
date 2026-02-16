/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_west.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:30:24 by msidry            #+#    #+#             */
/*   Updated: 2026/01/26 09:35:47 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	set_west_texture(t_error *err, t_textures *textures, char *line)
{
	static int	duplicate;
	char		*msg;

	if (err->stat)
		return ;
	texture_format_handler(err, &textures->west_txt, line);
	if (duplicate || textures->west_txt.type != IMAGE)
	{
		if (duplicate)
			msg = find_replace(ERROR_DUP, "$TXT", "west (WE) :", 0);
		else
			msg = find_replace(ERROR_ITXT, "$TXT", "west (WE) :", 0);
		setError(err, msg);
		setStat(err, EXIT_FAILURE);
		free(msg);
		return ;
	}
	duplicate = 1;
}
