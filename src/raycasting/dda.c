/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:31:07 by msidry            #+#    #+#             */
/*   Updated: 2026/02/22 15:25:41 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static double	ft_dabs(double value);

int	calculate_line_height(double perp_wall_dist, int height)
{
	int	line_height;

	if (perp_wall_dist == 0)
		return (height);
	line_height = (int)(height / perp_wall_dist);
	return (line_height);
}

double	get_perpendular(t_wall *wall, t_dda *data)
{
	double	perpen;

	if (wall->side == 0)
		perpen = data->side_dist_x - data->delta_dist_x;
	else
		perpen = data->side_dist_y - data->delta_dist_y;
	return (perpen);
}

void	performing_dda(t_container *ref, t_ray *ray)
{
	while (true)
	{
		if (ray->dda.side_dist_x < ray->dda.side_dist_y)
		{
			ray->dda.side_dist_x += ray->dda.delta_dist_x;
			ray->map_x += ray->wall.step_x;
			ray->wall.side = 0;
		}
		else
		{
			ray->dda.side_dist_y += ray->dda.delta_dist_y;
			ray->map_y += ray->wall.step_y;
			ray->wall.side = 1;
		}
		if ((ray->map_x < 0) || (ray->map_x >= ref->map.width) 
			|| (ray->map_y < 0) || (ray->map_y >= ref->map.height))
			break ;
		if (ref->map.map2d[ray->map_y][ray->map_x] == '1')
			break ;
	}
	ray->ppd = get_perpendular(&ray->wall, &ray->dda);
}

void	init_dda(t_container *ref, t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->dda.delta_dist_x = 1e20;
	else
		ray->dda.delta_dist_x = ft_dabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->dda.delta_dist_y = 1e20;
	else
		ray->dda.delta_dist_y = ft_dabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
		ray->dda.side_dist_x = (ref->player.pos.x - ray->map_x)
			* ray->dda.delta_dist_x;
	else
		ray->dda.side_dist_x = (ray->map_x + 1.0 - ref->player.pos.x)
			* ray->dda.delta_dist_x;
	if (ray->dir.y < 0)
		ray->dda.side_dist_y = (ref->player.pos.y - ray->map_y)
			* ray->dda.delta_dist_y;
	else
		ray->dda.side_dist_y = (ray->map_y + 1.0 - ref->player.pos.y)
			* ray->dda.delta_dist_y;
}

static double	ft_dabs(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}
