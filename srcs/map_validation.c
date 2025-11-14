#include "../includes/cub3d.h"

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_surrounding(t_game *game, int x, int y)
{
	if (x == 0 || x == game->map.width - 1)
		return (0);
	if (y == 0 || y == game->map.height - 1)
		return (0);
	if (game->map.grid[y - 1][x] == ' ')
		return (0);
	if (game->map.grid[y + 1][x] == ' ')
		return (0);
	if (game->map.grid[y][x - 1] == ' ')
		return (0);
	if (game->map.grid[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_borders(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (!is_valid_char(game->map.grid[y][x]))
				return (0);
			if ((game->map.grid[y][x] == '0' || \
				game->map.grid[y][x] == 'N' || \
				game->map.grid[y][x] == 'S' || \
				game->map.grid[y][x] == 'E' || \
				game->map.grid[y][x] == 'W'))
			{
				if (!check_surrounding(game, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	find_player(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
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
				count++;
			x++;
		}
		y++;
	}
	return (count == 1);
}

int	is_valid_map(t_game *game)
{
	if (!game->map.grid)
		return (0);
	if (!check_borders(game))
		return (0);
	if (!find_player(game))
		return (0);
	return (1);
}