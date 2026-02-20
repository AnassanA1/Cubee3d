/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:13:59 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:59 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	init_player(t_container *ref);
static void	set_player_direction(t_container *game, int dir);
static void	set_player_n(t_container *game);

void	game_init(t_container *ref)
{
	input_validator(ref);
	read_raw_config(ref);
	split_raw_config(&ref->datafile);
	valid_textures(ref);
	map_handler(ref);
	mlx_handler(ref, 1);
	textures_handler(ref, 1);
	init_player(ref);
}

static void	init_player(t_container *ref)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < ref->map.height)
	{
		x = 0;
		while (x < ref->map.width)
		{
			if (ref->map.map2d[y][x] > '1')
			{
				ref->player.pos.x = x + 0.5;
				ref->player.pos.y = y + 0.5;
				set_player_direction(ref, ref->map.map2d[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	set_player_direction(t_container *game, int dir)
{
	if (dir == 'N')
		set_player_n(game);
	else if (dir == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
		game->player.plane.x = -0.66;
		game->player.plane.y = 0;
	}
	else if (dir == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = -0.66;
	}
}

static void	set_player_n(t_container *game)
{
	game->player.dir.x = 0;
	game->player.dir.y = -1;
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
}
