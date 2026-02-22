/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:23:09 by msidry            #+#    #+#             */
/*   Updated: 2026/02/22 19:16:25 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static mlx_image_t	*get_wall_texture(t_container *ref, t_wall *wall);
static void			init_texture(t_container *ref, t_ray *ray, t_vline *line,
						t_txt *txt);

void	draw_floor_ceilling(t_container *ref)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < ref->display.height)
	{
		x = 0;
		while (x < ref->display.width)
		{
			if (y < ref->display.height / 2)
				put_pixel(ref->display.img, x, y, get_color(ref, SKY));
			else
				put_pixel(ref->display.img, x, y, get_color(ref, FLOOR));
			x++;
		}
		y++;
	}
}

void	draw_line(t_container *ref, t_ray *ray, t_vline *line)
{
	t_txt			txt;
	unsigned int	y;
	unsigned int	pixel;

	init_texture(ref, ray, line, &txt);
	y = line->start;
	while (y < line->end)
	{
		txt.y = (unsigned int)txt.pos % txt.texture->height;
		txt.pos += txt.step;
		pixel = get_pixel(txt.texture, ray->wall.tex_x, txt.y);
		put_pixel(ref->display.img, line->x, y, pixel);
		y++;
	}
}

static void	init_texture(t_container *ref, t_ray *ray, t_vline *line,
		t_txt *txt)
{
	double	wall_top;

	txt->texture = get_wall_texture(ref, &ray->wall);
	txt->step = (double)txt->texture->height / line->height;
	wall_top = ref->display.height / 2.0 - line->height / 2.0;
	txt->pos = (line->start - wall_top) * txt->step;
	if (ray->wall.side == 0)
		ray->wall_x = ref->player.pos.y + ray->ppd * ray->dir.y;
	else
		ray->wall_x = ref->player.pos.x + ray->ppd * ray->dir.x;
	ray->wall_x -= (int)(ray->wall_x);
	ray->wall.tex_x = (int)(ray->wall_x * txt->texture->width);
	if (ray->wall.tex_x >= (int)txt->texture->width)
		ray->wall.tex_x = txt->texture->width - 1;
}

static mlx_image_t	*get_wall_texture(t_container *ref, t_wall *wall)
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
