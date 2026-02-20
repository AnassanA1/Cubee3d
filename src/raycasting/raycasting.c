/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:13:48 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 19:00:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void		cast_ray(t_container *ref, int x);
void		init_ray(t_container *ref, t_ray *ray, int x);
void		init_dda(t_container *ref, t_ray *ray, t_dda *data);
void		init_step(t_ray *ray, t_wall *wall);
void		draw_wallp(t_container *ref, t_ray *ray, t_wall *wall, int x,
				int line_height, double perpen_dis);

void	raycasting(t_container *ref)
{
	unsigned int	x;

	x = 0;
	while (x < ref->display.width)
	{
		cast_ray(ref, x);
		x++;
	}
}

void	cast_ray(t_container *ref, int x)
{
	t_ray	ray;
	t_wall	wall;
	t_dda	data;
	double	perpen_dis;

	init_ray(ref, &ray, x);
	init_dda(ref, &ray, &data);
	init_step(&ray, &wall);
	performing_dda(ref, &ray, &data, &wall);
	perpen_dis = get_perpendular(&wall, &data);
	// draw_wall(ref, x, &wall, calculate_line_height(perpen_dis));
	draw_wallp(ref, &ray, &wall, x, calculate_line_height(perpen_dis,
			ref->display.height), perpen_dis);
}

void	init_ray(t_container *ref, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)ref->display.width - 1;
	ray->dir.x = ref->player.dir.x + ref->player.plane.x * ray->camera_x;
	ray->dir.y = ref->player.dir.y + ref->player.plane.y * ray->camera_x;
	ray->map_x = (int)ref->player.pos.x;
	ray->map_y = (int)ref->player.pos.y;
}

void	init_dda(t_container *ref, t_ray *ray, t_dda *data)
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
		data->side_dist_x = (ref->player.pos.x - ray->map_x)
			* data->delta_dist_x;
	else
		data->side_dist_x = (ray->map_x + 1.0 - ref->player.pos.x)
			* data->delta_dist_x;
	if (ray->dir.y < 0)
		data->side_dist_y = (ref->player.pos.y - ray->map_y)
			* data->delta_dist_y;
	else
		data->side_dist_y = (ray->map_y + 1.0 - ref->player.pos.y)
			* data->delta_dist_y;
}

void	init_step(t_ray *ray, t_wall *wall)
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

mlx_image_t	*get_wall_texture(t_container *ref, int side, int step_x,
		int step_y)
{
	if (side == 0) // Vertical wall (NS)
	{
		if (step_x > 0)
			return (get_texture_image(ref, EAST));
		else
			return (get_texture_image(ref, WEST));
	}
	else // Horizontal wall (EW)
	{
		if (step_y > 0)
			return (get_texture_image(ref, SOUTH));
		else
			return (get_texture_image(ref, NORTH));
	}
}

void	calculate_wall_x(t_container *ref, t_ray *ray, t_wall *wall,
		double perpen_dis)
{
	if (wall->side == 0)
		ray->wall_x = ref->player.pos.y + perpen_dis * ray->dir.y;
	else
		ray->wall_x = ref->player.pos.x + perpen_dis * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	calculate_tex_x(t_ray *ray, t_wall *wall, mlx_image_t *texture)
{
	wall->tex_x = (int)(ray->wall_x * (double)texture->width);
	if ((wall->side == 0 && ray->dir.x > 0) || (wall->side == 1
			&& ray->dir.y < 0))
		wall->tex_x = texture->width - wall->tex_x - 1;
}

int	get_texture_pixel(mlx_image_t *texture, int x, int y)
{
	int	index;
	int	color;
	int	*pixel;

	if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0x000000FF);
	index = (y * texture->width + x) * 4;
	pixel = (int *)(texture->pixels + index);
	color = *pixel;
	return (color);
}
// Modified draw_wall function with texture mapping
void	draw_wallp(t_container *ref, t_ray *ray, t_wall *wall, int x,
		int line_height, double perpen_dis)
{
	int			draw_start;
	int			draw_end;
	int			y;
	int			tex_y;
	int			color;
	mlx_image_t	*texture;
	double		step;
	double		tex_pos;

	// Calculate wall bounds
	draw_start = -line_height / 2 + ref->display.height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + ref->display.height / 2;
	if (draw_end >= (int)ref->display.height)
		draw_end = ref->display.height - 1;
	// Get the appropriate texture
	texture = get_wall_texture(ref, wall->side, wall->step_x, wall->step_y);
	// Calculate wall_x and tex_x
	calculate_wall_x(ref, ray, wall, perpen_dis);
	calculate_tex_x(ray, wall, texture);
	// Calculate texture y step
	step = (double)texture->height / line_height;
	tex_pos = (draw_start - ref->display.height / 2 + line_height / 2) * step;
	// Draw the textured wall stripe
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos % texture->height;
		if (tex_y < 0)
    		tex_y = 0;
		tex_pos += step;
		color = get_texture_pixel(texture, wall->tex_x, tex_y);
		put_pixel(ref->display.img, x, y, color);
		y++;
	}
}
