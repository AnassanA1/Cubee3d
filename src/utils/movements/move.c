/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:03:29 by msidry            #+#    #+#             */
/*   Updated: 2026/01/12 08:37:42 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.x * MOVE_SPEED;
	new_y = game->player.pos.y + game->player.dir.y * MOVE_SPEED;
	if (game->map.map2d[(int)game->player.pos.y][(int)new_x] != '1')
		game->player.pos.x = new_x;
	if (game->map.map2d[(int)new_y][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - game->player.dir.x * MOVE_SPEED;
	new_y = game->player.pos.y - game->player.dir.y * MOVE_SPEED;
	if (game->map.map2d[(int)game->player.pos.y][(int)new_x] != '1')
		game->player.pos.x = new_x;
	if (game->map.map2d[(int)new_y][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}

void	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - game->player.dir.y * MOVE_SPEED;
	new_y = game->player.pos.y + game->player.dir.x * MOVE_SPEED;
	if (game->map.map2d[(int)game->player.pos.y][(int)new_x] != '1')
		game->player.pos.x = new_x;
	if (game->map.map2d[(int)new_y][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}

void	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.y * MOVE_SPEED;
	new_y = game->player.pos.y - game->player.dir.x * MOVE_SPEED;
	if (game->map.map2d[(int)game->player.pos.y][(int)new_x] != '1')
		game->player.pos.x = new_x;
	if (game->map.map2d[(int)new_y][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}
