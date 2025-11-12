/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 06:24:02 by anasszgh          #+#    #+#             */
/*   Updated: 2025/11/12 06:24:08 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.west = NULL;
	game->textures.east = NULL;
	game->textures.north_tex = NULL;
	game->textures.south_tex = NULL;
	game->textures.west_tex = NULL;
	game->textures.east_tex = NULL;
	game->colors.floor_r = -1;
	game->colors.ceil_r = -1;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, false);
	if (!game->mlx)
		error_exit("MLX initialization failed");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
	{
		mlx_terminate(game->mlx);
		error_exit("Image creation failed");
	}
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)
	{
		mlx_delete_image(game->mlx, game->img);
		mlx_terminate(game->mlx);
		error_exit("Failed to display image");
	}
}

void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'N' || \
				game->map.grid[y][x] == 'S' || \
				game->map.grid[y][x] == 'E' || \
				game->map.grid[y][x] == 'W')
			{
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				set_player_direction(game, game->map.grid[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}