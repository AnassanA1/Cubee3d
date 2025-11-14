#include "../includes/cub3d.h"

int	get_line_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

char	**store_map_lines(int fd, int *height, int *width)
{
	char	**temp;
	char	*line;
	int		i;
	int		len;

	temp = malloc(sizeof(char *) * 1000);
	if (!temp)
		return (NULL);
	i = 0;
	*width = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			len = get_line_width(line);
			if (len > *width)
				*width = len;
			temp[i++] = line;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	*height = i;
	temp[i] = NULL;
	return (temp);
}

char	**allocate_map_grid(int height, int width)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		grid[i] = malloc(width + 1);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	grid[height] = NULL;
	return (grid);
}

void	fill_map_line(char *dest, char *src, int width)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n' && i < width)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < width)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
}

int	parse_map(int fd, t_game *game)
{
	char	**temp_lines;
	int		i;

	temp_lines = store_map_lines(fd, &game->map.height, &game->map.width);
	if (!temp_lines || game->map.height == 0)
		return (0);
	game->map.grid = allocate_map_grid(game->map.height, game->map.width);
	if (!game->map.grid)
	{
		i = 0;
		while (temp_lines[i])
			free(temp_lines[i++]);
		free(temp_lines);
		return (0);
	}
	i = 0;
	while (i < game->map.height)
	{
		fill_map_line(game->map.grid[i], temp_lines[i], game->map.width);
		free(temp_lines[i]);
		i++;
	}
	free(temp_lines);
	return (1);
}
