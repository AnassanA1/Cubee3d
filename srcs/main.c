#include "../includes/cub3d.h"

void	handle_movement(t_game *game)
{
	// Check all keys simultaneously!
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		strafe_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		strafe_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game);
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_movement(game);
	raycasting(game);
}

void	check_arguments(int argc, char **argv)
{
	int		len;
	char	*ext;

	if (argc != 2)
		error_exit("try ./cub3d <map.cub>");
	len = 0;
	while (argv[1][len])
		len++;
	if (len < 4)
		error_exit("Invalid map file");
	ext = &argv[1][len - 4];
	if (ext[0] != '.' || ext[1] != 'c' || \
		ext[2] != 'u' || ext[3] != 'b')
		error_exit("Map must be a .cub file");
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_arguments(argc, argv);
	init_game(&game);
	if (!parse_file(argv[1], &game))
		error_exit("Failed to parse map file");
	init_mlx(&game);
	mlx_key_hook(game.mlx, &key_hook, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(&game);
	return (0);
}