/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaryfloodfill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:35:04 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 02:04:50 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void	adjacent_neighbors(t_queue **q, t_map *map, size_t x, size_t y);

bool	is_closed_bff(t_map *map, t_queue **queue)
{
	bool	**visited;
	t_queue	out;

	if (!map || !queue || !*queue)
		return (false);
	visited = (bool **)alloc2darr(map->height, map->width, sizeof(bool));
	if (!visited)
		return (false);
	while (q_pop(queue, &out))
	{
		if (visited[out.y][out.x])
			continue ;
		visited[out.y][out.x] = true;
		if (out.content == '1')
			continue ;
		else if (out.content == ' ')
			adjacent_neighbors(queue, map, out.x, out.y);
		else
		{
			nullarr2d((void ***)&visited, map->height);
			return (false);
		}
	}
	nullarr2d((void ***)&visited, map->height);
	return (true);
}

static void	adjacent_neighbors(t_queue **queue, t_map *map, size_t x, size_t y)
{
	if (y > 0)
		q_push(queue, q_create(map->map2d[y - 1][x], x, y - 1));
	if (y < map->height - 1)
		q_push(queue, q_create(map->map2d[y + 1][x], x, y + 1));
	if (x > 0)
		q_push(queue, q_create(map->map2d[y][x - 1], x - 1, y));
	if (x < map->width - 1)
		q_push(queue, q_create(map->map2d[y][x + 1], x + 1, y));
}

bool	is_nospace_bff(t_map *map, t_queue **queue)
{
	bool	**visited;
	t_queue	out;

	if (!map || !queue || !*queue)
		return (false);
	visited = (bool **)alloc2darr(map->height, map->width, sizeof(bool));
	if (!visited)
		return (false);
	while (q_pop(queue, &out))
	{
		if (visited[out.y][out.x])
			continue ;
		visited[out.y][out.x] = true;
		if (out.content == '1')
			continue ;
		else if (out.content == ' ')
		{
			nullarr2d((void ***)&visited, map->height);
			return (false);
		}
		else
			adjacent_neighbors(queue, map, out.x, out.y);
	}
	nullarr2d((void ***)&visited, map->height);
	return (true);
}
