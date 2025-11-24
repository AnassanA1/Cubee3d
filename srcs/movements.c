/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:10:40 by azghibat          #+#    #+#             */
/*   Updated: 2025/11/23 12:37:54 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	
	if (game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	
	if (game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;

	// Perpendicular to direction = (-dir_y, dir_x)
	new_x = game->player.pos_x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_x * MOVE_SPEED;
	
	if (game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED;
	
	if (game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	
	game->player.dir_x = game->player.dir_x * cos(ROT_SPEED) - \
		game->player.dir_y * sin(ROT_SPEED);
	game->player.dir_y = old_dir_x * sin(ROT_SPEED) + \
		game->player.dir_y * cos(ROT_SPEED);
	
	game->player.plane_x = game->player.plane_x * cos(ROT_SPEED) - \
		game->player.plane_y * sin(ROT_SPEED);
	game->player.plane_y = old_plane_x * sin(ROT_SPEED) + \
		game->player.plane_y * cos(ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	
	game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED) - \
		game->player.dir_y * sin(-ROT_SPEED);
	game->player.dir_y = old_dir_x * sin(-ROT_SPEED) + \
		game->player.dir_y * cos(-ROT_SPEED);
	
	game->player.plane_x = game->player.plane_x * cos(-ROT_SPEED) - \
		game->player.plane_y * sin(-ROT_SPEED);
	game->player.plane_y = old_plane_x * sin(-ROT_SPEED) + \
		game->player.plane_y * cos(-ROT_SPEED);
}