/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:28:49 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/16 10:30:51 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	normaize_width(t_map *map, unsigned char toapp)
{
	size_t	idx;

	idx = 0;
	while (map->map2d[idx])
	{
		map->map2d[idx] = normalize(map->map2d[idx], map->width + 1, toapp);
		idx++;
	}
}

bool	space_in_path(t_error *error, t_map *map) // fix 25 line.
{
	t_queue	*queue;
	size_t	x;
	size_t	y;
	bool	isfound;

	queue = NULL;
	y = -1;
	isfound = 0;
	while (map->map2d[++y] && !isfound)
	{
		x = -1;
		while (map->map2d[y][++x])
		{
			if (ft_strchr("NEWS", map->map2d[y][x]))
			{
				q_push(&queue, q_create(map->map2d[y][x], x, y));
				break ;
			}
		}
	}
	if (is_nospace_bff(map, &queue))
		return (true);
	setError(error, BAD_P_MAP);
	setStat(error, 1);
	q_empty(&queue);
	return (false);
}
