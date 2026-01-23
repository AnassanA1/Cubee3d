/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:54:25 by msidry            #+#    #+#             */
/*   Updated: 2026/01/22 06:51:18 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static bool empty_line(t_error *error, char *line);
static bool supported_line(t_error *error,char *line);
static bool one_direction(t_error *error, char **arr);
static bool closed_map(t_error *error, t_map *map);
static bool space_in_path(t_error *error, t_map *map);

void map_validator(t_game *ref)
{
	size_t	idx;

	idx = 0;
	if (!isAllOk(ref))
		return ;
	if (!one_direction(&ref->error, ref->map.map2d))
		return ;
	while (ref->map.map2d[idx])
	{
		if (empty_line(&ref->error, ref->map.map2d[idx]))
			return ;
		if (!supported_line(&ref->error, ref->map.map2d[idx]))
			return ;
		idx++;
	}
	normaize_width(&ref->map, ' ');
	if (!isAllOk(ref))
		return ;
	if (!closed_map(&ref->error, &ref->map))
		return ;
	if (!isAllOk(ref))
		return ;
	space_in_path(&ref->error, &ref->map);
}




static bool empty_line(t_error *error, char *line)
{
    char *err;

    if (!*line || contain_only(line, SPACES) )
    {
        if (error)
        {
            err = find_replace(ERROR_GENERAL, "$MSG", BAD_E_LINE, 0);
            setError(error, err);
            setStat(error, EXIT_FAILURE);
            nullstr(&err);
        }
        return (true);  
    }
    return (false);
}

static bool supported_line(t_error *error,char *line)
{
    char *err;
    if (!contain_only(line, MAPSET))
    {
        err = find_replace(ERROR_GENERAL, "$MSG", BAD_C_LINE, 0);
        setError(error, BAD_C_LINE);
        setStat(error, EXIT_FAILURE);
        nullstr(&err);
        return (false);
    }
    return (true);
}



static bool one_direction(t_error *error, char **arr)
{
    size_t y;
    size_t x;
    size_t count;
    char *message;

    y = -1;
    count = 0;
    while (arr && arr[++y])
    {
        x = -1;
        while (arr[y][++x])
        {
            if (match_count("NEWS", arr[y][x]))
                count++;
        }
    }
    if (count != 1)
    {
        message = find_replace(ERROR_GENERAL, "$MSG", BAD_D_LINE, 0);
        setError(error, message);
        setStat(error, EXIT_FAILURE);
        nullstr(&message);
    }
    return (count == 1);
}

static bool closed_map(t_error *error, t_map *map)
{
    t_queue *queue;
    size_t x;
    size_t y;

    y = 0;
    queue = NULL;
    while (map->map2d[y])
    {
        x = 0;
        while (map->map2d[y][x])
        {
            if (x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
                q_push(&queue, q_create(map->map2d[y][x], x, y));
            x++;
        }
        y++;
    }
    if (is_closed_bff(map, &queue))
        return (true);
    setError(error, BAD_C_MAP);
    setStat(error, 1);
    q_empty(&queue);
    return (false);
}



static bool space_in_path(t_error *error, t_map *map)
{
    t_queue *queue;
    size_t x;
    size_t y;
    bool isfound;
    
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
                break;
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
