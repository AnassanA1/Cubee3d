/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:13:48 by msidry            #+#    #+#             */
/*   Updated: 2026/02/21 14:04:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void		cast_ray(t_container *ref, int x);
void		init_ray(t_container *ref, t_ray *ray, int x);
void		init_step(t_ray *ray);
void		draw_wallp(t_container *ref, t_ray *ray, int x);

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

	init_ray(ref, &ray, x);
	init_step(&ray);
	init_dda(ref, &ray);
	performing_dda(ref, &ray);
	ray.wall.perp_dist = get_perpendular(&ray.wall, &ray.dda);
	ray.wall.line_height = calculate_line_height(ray.wall.perp_dist, ref->display.height);
	draw_wallp(ref, &ray, x);
}

void	init_ray(t_container *ref, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)ref->display.width - 1;
	ray->dir.x = ref->player.dir.x + ref->player.plane.x * ray->camera_x;
	ray->dir.y = ref->player.dir.y + ref->player.plane.y * ray->camera_x;
	ray->map_x = (int)ref->player.pos.x;
	ray->map_y = (int)ref->player.pos.y;
}


void	init_step(t_ray *ray)
{
	if (ray->dir.x < 0)
		ray->wall.step_x = -1;
	else
		ray->wall.step_x = 1;
	if (ray->dir.y < 0)
		ray->wall.step_y = -1;
	else
		ray->wall.step_y = 1;
}


mlx_image_t	*get_wall_texture(t_container *ref, t_wall *wall)
{
	if (wall->side == 0)
	{
		if (wall->step_x > 0)
			return (get_texture_image(ref, EAST));
		else
			return (get_texture_image(ref, WEST));
	}
	else
	{
		if (wall->step_y > 0)
			return (get_texture_image(ref, SOUTH));
		else
			return (get_texture_image(ref, NORTH));
	}
}

void	calculate_wall_x(t_container *ref, t_ray *ray, t_wall *wall, double perpen_dis)
{
	if (wall->side == 0)
		ray->wall_x = ref->player.pos.y + perpen_dis * ray->dir.y;
	else
		ray->wall_x = ref->player.pos.x + perpen_dis * ray->dir.x;
	ray->wall_x -= (int)(ray->wall_x);
}

void	calculate_tex_x(t_ray *ray, t_wall *wall, mlx_image_t *texture)
{
	wall->tex_x = (int)(ray->wall_x * (double)texture->width);
	//if ((wall->side == 0 && ray->dir.x > 0) || (wall->side == 1
	//		&& ray->dir.y < 0))
	//	wall->tex_x = texture->width - wall->tex_x - 1;
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


int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}


int min(int a , int b)
{
	if (a > b)
		return b;
	return (a);
}

void	draw_wallp(t_container *ref, t_ray *ray, int x)
{
	unsigned int			y;
	int			tex_y;
	int			color;
	mlx_image_t	*texture;
	double		tex_pos;
	t_line		line;

	// Calculate wall bounds
	line.y_start = max(-ray->wall.line_height / 2 + ref->display.height / 2, 0);
	line.y_end = min(ray->wall.line_height / 2 + ref->display.height / 2, ref->display.height - 1);
	// Get the appropriate texture
	texture = get_wall_texture(ref, &ray->wall);
	line.step = (double)texture->height / ray->wall.line_height;
	// Calculate wall_x and tex_x
	calculate_wall_x(ref, ray, &ray->wall, ray->wall.perp_dist);
	calculate_tex_x(ray, &ray->wall, texture);
	// Calculate texture y step
	tex_pos = (line.y_start - ref->display.height / 2 + ray->wall.line_height / 2) * line.step;
	// Draw the textured wall stripe
	y = line.y_start;
	while (y < line.y_end)
	{
		tex_y = (int)tex_pos % texture->height;
		if (tex_y < 0)
    		tex_y = 0;
		tex_pos += line.step;
		color = get_texture_pixel(texture, ray->wall.tex_x, tex_y);
		put_pixel(ref->display.img, x, y, color);
		y++;
	}
}



