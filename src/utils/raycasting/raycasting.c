/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:13:48 by msidry            #+#    #+#             */
/*   Updated: 2026/01/19 16:16:14 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"



void    raycasting(t_game *game)
{
    int x;

    draw_floor_ceilling(game);
    x = 0;
    while (x < WIN_WIDTH)
    {
        cast_ray(game, x);
        x++;
    }
}

void    init_ray(t_game *game, t_ray *ray, int x)
{
    ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
    ray->dir.x = game->player.dir.x + game->player.plane.x * ray->camera_x;
    ray->dir.y = game->player.dir.y + game->player.plane.y * ray->camera_x;
    ray->map_x = (int)game->player.pos.x; 
    ray->map_y = (int)game->player.pos.y; 
}

void    init_dda(t_game *game, t_ray *ray, t_dda *data)
{
    if (ray->dir.x == 0)
        data->delta_dist_x = 1e20;
    else
        data->delta_dist_x = fabs(1 / ray->dir.x);
    
    if (ray->dir.y == 0)
        data->delta_dist_y = 1e20;
    else
        data->delta_dist_y = fabs(1 / ray->dir.y);
    if (ray->dir.x < 0)
        data->side_dist_x = (game->player.pos.x - ray->map_x) * data->delta_dist_x;
    else
        data->side_dist_x = (ray->map_x + 1.0 - game->player.pos.x) * data->delta_dist_x;
    if (ray->dir.y < 0)
        data->side_dist_y = (game->player.pos.y - ray->map_y) * data->delta_dist_y;
    else
        data->side_dist_y = (ray->map_y + 1.0 - game->player.pos.y) * data->delta_dist_y;
}

void    init_step(t_ray *ray, t_wall *wall)
{
    wall->hit = 0;
    if (ray->dir.x < 0)
        wall->step_x = -1;
    else
        wall->step_x = 1;
    if (ray->dir.y < 0)
        wall->step_y = -1;
    else
        wall->step_y = 1;
}

void    cast_ray(t_game *game, int x)
{
    t_ray   ray;
    t_wall  wall;
    t_dda   data;
    double  perpen_dis;

    init_ray(game, &ray, x);
    init_dda(game, &ray, &data);
    init_step(&ray, &wall);
    performing_dda(game, &ray, &data, &wall);
    perpen_dis = get_perpendular(&wall, &data);
    draw_wall(game, x, &wall, calculate_line_height(perpen_dis));
}