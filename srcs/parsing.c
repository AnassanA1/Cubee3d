#include "../includes/cub3d.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open file");
	return (fd);
}

int	all_textures_loaded(t_game *game)
{
	if (!game->textures.north)
		return (0);
	if (!game->textures.south)
		return (0);
	if (!game->textures.west)
		return (0);
	if (!game->textures.east)
		return (0);
	if (game->colors.floor_r == -1)
		return (0);
	if (game->colors.ceil_r == -1)
		return (0);
	return (1);
}
int	parse_file(char *filename, t_game *game)
{
	int	fd;

	fd = open_file(filename);
	if (!parse_textures(fd, game))
	{
		close(fd);
		return (0);
	}
	if (!parse_map(fd, game))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!all_textures_loaded(game))
		return (0);
	if (!is_valid_map(game))
		return (0);
	init_player(game);
	return (1);
}
