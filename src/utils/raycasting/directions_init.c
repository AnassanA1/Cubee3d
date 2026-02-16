/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:46:16 by azghibat          #+#    #+#             */
/*   Updated: 2026/01/26 12:50:58 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	set_player_direction(t_game *game, int dir)
{
	if (dir == 'N')
		set_player_direstion_north(game);
	else if (dir == 'S')
		set_player_direction_south(game);
	else if (dir == 'E')
		set_playe_direction_east(game);
	else if (dir == 'W')
		set_player_diresction_west(game);
}

void	set_player_direstion_north(t_game *game)
{
	game->player.dir.x = 0;
	game->player.dir.y = -1;
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
}

void	set_player_direction_south(t_game *game)
{
	game->player.dir.x = 0;
	game->player.dir.y = 1;
	game->player.plane.x = -0.66;
	game->player.plane.y = 0;
}

void	set_playe_direction_east(t_game *game)
{
	game->player.dir.x = 1;
	game->player.dir.y = 0;
	game->player.plane.x = 0;
	game->player.plane.y = 0.66;
}

void	set_player_diresction_west(t_game *game)
{
	game->player.dir.x = -1;
	game->player.dir.y = 0;
	game->player.plane.x = 0;
	game->player.plane.y = -0.66;
}
