/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:13:48 by msidry            #+#    #+#             */
/*   Updated: 2026/02/22 18:14:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void		cast_ray(t_container *ref, int x);
void		init_ray(t_container *ref, t_ray *ray, int x);
void		init_step(t_ray *ray);





int max(int a, int b);
int min(int a , int b);
void init_line(t_container *ref, t_ray *ray, t_vline *line, unsigned int x);


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
	t_vline	vline;

	init_ray(ref, &ray, x);
	init_step(&ray);
	init_dda(ref, &ray);
	performing_dda(ref, &ray);
	init_line(ref, &ray, &vline, x);
	draw_line(ref, &ray, &vline);
}

void init_line(t_container *ref, t_ray *ray, t_vline *line, unsigned int x)
{
    t_display *dsp = &ref->display;

    line->x = x;
    line->height = calculate_line_height(ray->ppd, dsp->height);
    line->start = max(dsp->height / 2 - line->height / 2, 0);
    line->end   = min(dsp->height / 2 + line->height / 2,
                      dsp->height - 1);
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
