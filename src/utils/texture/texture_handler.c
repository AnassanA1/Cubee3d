/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:16:19 by msidry            #+#    #+#             */
/*   Updated: 2026/02/16 10:37:33 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void	valid_textures(t_error *error, t_textures *textuers);
static int	texture_config_handler(t_error *error, t_textures *txts,
				char *line);

void	texture_handler(t_game *ref)
{
	t_list	*list;
	char	*line;

	if (!isAllOk(ref))
		return ;
	list = ref->scene.rawmap;
	while (list)
	{
		line = (char *)list->content;
		if (is_map_config(line))
		{
			if (texture_config_handler(&ref->error, &ref->textures, line))
				return ;
		}
		list = list->next;
	}
	valid_textures(&ref->error, &ref->textures);
}

static int	texture_config_handler(t_error *error, t_textures *txts, char *line) // fix 25 line
{
	static char			*identifiers[6];
	static callconfi	callbacks[6];
	size_t				idx;

	identifiers[0] = SOUTH;
	identifiers[1] = NORTH;
	identifiers[2] = EAST;
	identifiers[3] = WEST;
	identifiers[4] = SKY;
	identifiers[5] = FLOOR;
	callbacks[0] = set_south_texture;
	callbacks[1] = set_north_texture;
	callbacks[2] = set_east_texture;
	callbacks[3] = set_west_texture;
	callbacks[4] = set_sky_texture;
	callbacks[5] = set_floor_texture;
	idx = -1;
	while (++idx < 6)
	{
		if (!ft_strncmp(identifiers[idx], line, ft_strlen(identifiers[idx])))
		{
			callbacks[idx](error, txts, line);
			return (error->stat);
		}
	}
	return (0);
}

static void	valid_textures(t_error *error, t_textures *textuers)
{
	char	*notset;

	notset = NULL;
	if (!textuers->north_txt.is_set)
		notset = "NORTH";
	else if (!textuers->south_txt.is_set)
		notset = "NORTH";
	else if (!textuers->west_txt.is_set)
		notset = "WEST";
	else if (!textuers->east_txt.is_set)
		notset = "EAST";
	else if (!textuers->sky_txt.is_set)
		notset = "SKY";
	else if (!textuers->floor_txt.is_set)
		notset = "FLOOR";
	if (notset)
	{
		notset = find_replace(ERROR_TXT, "$MSG", notset, 0);
		setError(error, notset);
		setStat(error, EXIT_FAILURE);
		nullstr(&notset);
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
		txts[idx]->texture.img_texture.txt = mlx_texture_to_image(ref->display.mlx,
				raw);
		mlx_delete_texture(raw);
		if (!txts[idx]->texture.img_texture.txt)
			exit(fprintf(stderr, "Error: Failed to convert texture\n"));
	}
}
