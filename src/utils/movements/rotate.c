/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:04:01 by msidry            #+#    #+#             */
/*   Updated: 2026/01/12 09:17:08 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	old_plane_x = game->player.plane.x;
	
	game->player.dir.x = game->player.dir.x * cos(-ROT_SPEED) - \
		game->player.dir.y * sin(-ROT_SPEED);
	game->player.dir.y = old_dir_x * sin(-ROT_SPEED) + \
		game->player.dir.y * cos(-ROT_SPEED);
	
	game->player.plane.x = game->player.plane.x * cos(-ROT_SPEED) - \
		game->player.plane.y * sin(-ROT_SPEED);
	game->player.plane.y = old_plane_x * sin(-ROT_SPEED) + \
		game->player.plane.y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	old_plane_x = game->player.plane.x;
	
	game->player.dir.x = game->player.dir.x * cos(ROT_SPEED) - \
		game->player.dir.y * sin(ROT_SPEED);
	game->player.dir.y = old_dir_x * sin(ROT_SPEED) + \
		game->player.dir.y * cos(ROT_SPEED);
	
	game->player.plane.x = game->player.plane.x * cos(ROT_SPEED) - \
		game->player.plane.y * sin(ROT_SPEED);
	game->player.plane.y = old_plane_x * sin(ROT_SPEED) + \
		game->player.plane.y * cos(ROT_SPEED);
}