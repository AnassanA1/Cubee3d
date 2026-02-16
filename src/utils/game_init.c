/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:13:59 by msidry            #+#    #+#             */
/*   Updated: 2026/01/26 12:53:26 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	init_default(t_game *ref, int argc, char *argv[]);
void		init_mlx(t_game *ref);
static void	init_player(t_game *ref);
void		load_texture(t_game *ref);

void	game_init(t_game **ref, int argc, char *argv[])
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
	mostBeGood(ref);
	init_player(*ref);
	init_mlx(*ref);
	load_texture(*ref);
}

static void	init_player(t_game *ref)
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

static void	init_default(t_game *ref, int argc, char *argv[])
{
	ref->argc = argc;
	ref->argv = argv;
	ref->scene.path = argv[1];
	ref->scene.fd = -1;
}

void	init_mlx(t_game *game)
{
	if (!isAllOk(game))
		return ;
	game->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, true);
	if (!game->display.mlx)
		exit(fprintf(stderr, "MLX initialization failed\n"));
	game->display.img = mlx_new_image(game->display.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->display.img)
	{
		mlx_terminate(game->display.mlx);
		exit(fprintf(stderr, "MLX initialization failed\n"));
	}
	if (mlx_image_to_window(game->display.mlx, game->display.img, 0, 0) < 0)
	{
		mlx_delete_image(game->display.mlx, game->display.img);
		mlx_terminate(game->display.mlx);
		exit(fprintf(stderr, "MLX initialization failed\n"));
	}
}
