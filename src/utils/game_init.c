/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:13:59 by msidry            #+#    #+#             */
/*   Updated: 2026/01/22 06:21:05 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void init_default(t_game *ref, int argc, char *argv[]);
static void init_player(t_game *ref);
static void set_player_direction(t_game *game, int dir);
void	init_mlx(t_game *ref);
void	load_texture(t_game *ref);
void game_init(t_game**ref, int argc, char *argv[])
{
    *ref = ft_calloc(1, sizeof(t_game));
    if (!*ref)
    {
        ft_putendl_fd(strerror(errno), 2);
        exit(EXIT_FAILURE);
    }
    init_default(*ref, argc, argv);
    input_handler(*ref);
    config_handler(*ref);
    //config_info(*ref);
    mostBeGood(ref);
    init_player(*ref);
    init_mlx(*ref);
	load_texture(*ref);
}

static void init_default(t_game *ref, int argc, char *argv[])
{
    ref->argc = argc;
    ref->argv = argv;
    ref->scene.path = argv[1];
    ref->scene.fd = -1;
}


static void init_player(t_game *ref)
{
    size_t	x;
	size_t	y;

	y = 0;
	if (!ref || !isAllOk(ref))
		return ;
	while (y < ref->map.height)
	{
		x = 0;
		while (x < ref->map.width)
		{
			if (ref->map.map2d[y][x] > '1')
			{
				ref->player.pos.x = x + 0.5; // why 0,5 ? each grid cell is 1 unit wide, so to place the player in the center of the cell we add 0.5
				ref->player.pos.y = y + 0.5;
				set_player_direction(ref, ref->map.map2d[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_mlx(t_game *game)
{
	if (!isAllOk(game))
		return ;
	game->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, true);
	if (!game->display.mlx)
        exit (fprintf(stderr, "MLX initialization failed\n"));
	game->display.img = mlx_new_image(game->display.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->display.img)
	{
		mlx_terminate(game->display.mlx);
		exit (fprintf(stderr, "MLX initialization failed\n"));
	}
	if (mlx_image_to_window(game->display.mlx, game->display.img, 0, 0) < 0)
	{
		mlx_delete_image(game->display.mlx, game->display.img);
		mlx_terminate(game->display.mlx);
		exit (fprintf(stderr, "MLX initialization failed\n"));
	}
}


static void set_player_direction(t_game *game, int dir)
{
    if (dir == 'N')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.plane.x = 0.66;
		game->player.plane.y = 0;
	}
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

void	load_texture(t_game *ref)
{
	int				idx;
	mlx_texture_t	*raw;
	t_texture		*txts[4];

	if (!ref || !isAllOk(ref))
		return ;
	txts[0] = &ref->textures.north_txt;
	txts[1] = &ref->textures.south_txt;
	txts[2] = &ref->textures.east_txt;
	txts[3] = &ref->textures.west_txt;
	idx = -1;
	while (++idx < 4)
	{
		if (txts[idx]->type != IMAGE)
			continue ;
		raw = mlx_load_png(txts[idx]->texture.img_texture.path);
		if (!raw)
			exit(fprintf(stderr, "Error: Failed to load texture\n"));
		txts[idx]->texture.img_texture.txt = mlx_texture_to_image(
				ref->display.mlx, raw);
		mlx_delete_texture(raw);
		if (!txts[idx]->texture.img_texture.txt)
			exit(fprintf(stderr, "Error: Failed to convert texture\n"));
	}
}
