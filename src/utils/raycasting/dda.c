/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:35:54 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/16 10:36:14 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

int	calculate_line_height(double perp_wall_dist)
{
	int	line_height;

	if (perp_wall_dist == 0)
		return (WIN_HEIGHT);
	line_height = (int)(WIN_HEIGHT / perp_wall_dist);
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

void	init_dda(t_game *game, t_ray *ray, t_dda *data)
{
	if (ray->dir.x == 0)
		data->delta_dist_x = INFINITY;
	else
		data->delta_dist_x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		data->delta_dist_y = INFINITY;
	else
		data->delta_dist_y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
		data->side_dist_x = (game->player.pos.x - ray->map_x)
			* data->delta_dist_x;
	else
		data->side_dist_x = (ray->map_x + 1.0 - game->player.pos.x)
			* data->delta_dist_x;
	if (ray->dir.y < 0)
		data->side_dist_y = (game->player.pos.y - ray->map_y)
			* data->delta_dist_y;
	else
		data->side_dist_y = (ray->map_y + 1.0 - game->player.pos.y)
			* data->delta_dist_y;
}

void	performing_dda(t_game *game, t_ray *ray, t_dda *dda, t_wall *wall)
{
	wall->hit = 0;
	while (wall->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			ray->map_x += wall->step_x;
			wall->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			ray->map_y += wall->step_y;
			wall->side = 1;
		}
		if ((ray->map_x < 0) || (ray->map_x >= game->map.width)
			|| (ray->map_y < 0) || (ray->map_y >= game->map.height))
		{
			wall->hit = 1;
			break ;
		}
		if (game->map.map2d[ray->map_y][ray->map_x] == '1')
			wall->hit = 1;
	}
}
