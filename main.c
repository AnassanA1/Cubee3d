/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:14:17 by msidry            #+#    #+#             */
/*   Updated: 2026/01/26 12:49:48 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

static void	leakcheck(void);

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->display.mlx);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = NULL;
	game_init(&game, argc, argv);
	mlx_key_hook(game->display.mlx, &key_hook, game);
	mlx_loop_hook(game->display.mlx, &game_loop, game);
	mlx_loop(game->display.mlx);
	game_destroy(&game);
	atexit(leakcheck);
	return (0);
}

static void	leakcheck(void)
{
	system("leaks -q cube3D");
}
