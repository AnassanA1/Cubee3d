#include "../includes/cub3d.h"

char	*trim_newline(char *str)
{
	int		i;
	char	*result;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = str[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*skip_spaces(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

int	parse_texture_line(char *line, t_game *game)
{
	char	*path;

	line = skip_spaces(line);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		path = skip_spaces(line + 3);
		game->textures.north = trim_newline(path);
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		path = skip_spaces(line + 3);
		game->textures.south = trim_newline(path);
	}
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		path = skip_spaces(line + 3);
		game->textures.west = trim_newline(path);
	}
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		path = skip_spaces(line + 3);
		game->textures.east = trim_newline(path);
	}
	else if (line[0] == 'F' && line[1] == ' ')
		return (parse_color(line + 2, &game->colors, 0));
	else if (line[0] == 'C' && line[1] == ' ')
		return (parse_color(line + 2, &game->colors, 1));
	return (1);
}

int	parse_color(char *line, t_colors *colors, int is_ceiling)
{
	int	r;
	int	g;
	int	b;

	line = skip_spaces(line);
	r = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	if (*line == ',')
		line++;
	line = skip_spaces(line);
	g = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	if (*line == ',')
		line++;
	line = skip_spaces(line);
	b = ft_atoi(line);
	if (is_ceiling)
	{
    	colors->ceil_r = r;
    	colors->ceil_g = g;
    	colors->ceil_b = b;
	}
	else
	{
		colors->floor_r = r;
		colors->floor_g = g;
		colors->floor_b = b;
	}	
	return (1);
}

int	parse_textures(int fd, t_game *game)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && count < 6)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			if (!parse_texture_line(line, game))
			{
				free(line);
				return (0);
			}
			count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (count == 6);
}
