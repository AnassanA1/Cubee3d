/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:13:48 by msidry            #+#    #+#             */
/*   Updated: 2026/01/22 10:32:13 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void draw_wallp(t_game *game, int x, t_wall *wall, int line_height, double perpen_dis, t_ray *);

void    raycasting(t_game *game)
{
    int x;

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
    draw_wallp(game, x, &wall, calculate_line_height(perpen_dis), perpen_dis, &ray);
}

// Helper function to get texture pixel color
int get_texture_pixel(mlx_image_t *texture, int x, int y)
{
    int index;
    int color;

    if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
        return (0x000000FF);
    
    index = (y * texture->width + x) * 4;
    color = (texture->pixels[index] << 24) |
            (texture->pixels[index + 1] << 16) |
            (texture->pixels[index + 2] << 8) |
            texture->pixels[index + 3];
    return (color);
}

// Get the appropriate texture based on wall direction
mlx_image_t *get_wall_texture(t_textures *txt, int side, int step_x, int step_y)
{
    if (side == 0) // Vertical wall (NS)
    {
        if (step_x > 0)
            return (txt->east_txt.texture.img_texture.txt);  // East wall
        else
            return (txt->west_txt.texture.img_texture.txt);  // West wall
    }
    else // Horizontal wall (EW)
    {
        if (step_y > 0)
            return (txt->south_txt.texture.img_texture.txt); // South wall
        else
            return (txt->north_txt.texture.img_texture.txt); // North wall
    }
}

void calculate_wall_x(t_game *game, t_ray *ray, t_wall *wall, double perpen_dis)
{
    if (wall->side == 0)
        ray->wall_x = game->player.pos.y + perpen_dis * ray->dir.y;
    else
        ray->wall_x = game->player.pos.x + perpen_dis * ray->dir.x;
    
    ray->wall_x -= floor(ray->wall_x);
    
}

void calculate_tex_x(t_ray *ray, t_wall *wall, mlx_image_t *texture)
{
    wall->tex_x = (int)(ray->wall_x * (double)texture->width);
    
    if ((wall->side == 0 && ray->dir.x > 0) || 
        (wall->side == 1 && ray->dir.y < 0))
        wall->tex_x = texture->width - wall->tex_x - 1;
}

// Modified draw_wall function with texture mapping
void draw_wallp(t_game *game, int x, t_wall *wall, int line_height, double perpen_dis, t_ray *ray)
{
    int             draw_start;
    int             draw_end;
    int             y;
    int             tex_y;
    int             color;
    mlx_image_t     *texture;
    double          step;
    double          tex_pos;

    // Calculate wall bounds
    draw_start = -line_height / 2 + WIN_HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + WIN_HEIGHT / 2;
    if (draw_end >= WIN_HEIGHT)
        draw_end = WIN_HEIGHT - 1;

    // Get the appropriate texture
    texture = get_wall_texture(&game->textures, wall->side, wall->step_x, wall->step_y);
    
    // Calculate wall_x and tex_x
    calculate_wall_x(game, ray, wall, perpen_dis);
    calculate_tex_x(ray, wall, texture);

    // Calculate texture y step
    step = (double)texture->height / line_height;
    tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;

    // Draw the textured wall stripe
    y = draw_start;
    while (y < draw_end)
    {
        tex_y = (int)tex_pos & (texture->height - 1);
        tex_pos += step;
        color = get_texture_pixel(texture, wall->tex_x, tex_y);
        put_pixel(game->display.img, x, y, color);
        y++;
    }
}
