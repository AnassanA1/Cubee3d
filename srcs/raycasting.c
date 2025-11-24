/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:29:53 by azghibat          #+#    #+#             */
/*   Updated: 2025/11/24 11:42:51 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_ray(t_game *game, t_ray *ray, int x)
{
    ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
    ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
    ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
    ray->map_x = (int)game->player.pos_x; 
    ray->map_y = (int)game->player.pos_y; 
}

void    init_dda(t_game *game, t_ray *ray, t_dda *data)
{
    if (ray->ray_dir_x == 0)
        data->delta_dist_x = 1e20;
    else
        data->delta_dist_x = fabs(1 / ray->ray_dir_x);
    
    if (ray->ray_dir_y == 0)
        data->delta_dist_y = 1e20;
    else
        data->delta_dist_y = fabs(1 / ray->ray_dir_y);
    if (ray->ray_dir_x < 0)
        data->side_dist_x = (game->player.pos_x - ray->map_x) * data->delta_dist_x;
    else
        data->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x) * data->delta_dist_x;
    if (ray->ray_dir_y < 0)
        data->side_dist_y = (game->player.pos_y - ray->map_y) * data->delta_dist_y;
    else
        data->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y) * data->delta_dist_y;
}

void    init_step(t_ray *ray, t_wall *wall)
{
    wall->hit = 0;
    if (ray->ray_dir_x < 0)
        wall->step_x = -1;
    else
        wall->step_x = 1;
    if (ray->ray_dir_y < 0)
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
