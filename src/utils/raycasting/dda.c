/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:31:07 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 02:09:37 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

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

void	performing_dda(t_container *game, t_ray *ray, t_dda *dda, t_wall *wall)
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
// mark as vertical line |
// mark as horizental line --
