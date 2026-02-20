/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:47:43 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 17:01:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void	init_map(t_container *ref);
static void	set_height_width(t_map *map);

void	map_handler(t_container *ref)
{
	init_map(ref);
	map_validator(ref);
}

static void	init_map(t_container *ref)
{
	char	**raw2d;
	char	*err;

	raw2d = serializer(ref->datafile.map);
	ref->map.map2d = trim_tail_empty(raw2d);
	if (!ref->map.map2d)
	{
		err = find_replace(ERROR_GENERAL, "$MSG", "Empty map", 0);
		ft_putstr_fd(err, STDERR_FILENO);
		nullarr2d((void ***)&raw2d, str2dlen(raw2d));
		game_destroy(ref);
		nullstr(&err);
		exit(EXIT_FAILURE);
	}
	nullarr2d((void ***)&raw2d, str2dlen(raw2d));
	set_height_width(&ref->map);
}

static void	set_height_width(t_map *map)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	while (map->map2d[idx])
	{
		len = ft_strlen(map->map2d[idx]);
		if (len > map->width)
			map->width = len;
		idx++;
		map->height++;
	}
}
