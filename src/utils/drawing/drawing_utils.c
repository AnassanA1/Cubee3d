/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 06:22:09 by anasszgh          #+#    #+#             */
/*   Updated: 2026/01/22 06:22:30 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void	get_draw_bounds(int line_h, int *start, int *end)
{
	*start = -line_h / 2 + WIN_HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = line_h / 2 + WIN_HEIGHT / 2;
	if (*end >= WIN_HEIGHT)
		*end = WIN_HEIGHT - 1;
}

static void	draw_textured_stripe(t_game *g, int x, t_wall *w,
	mlx_image_t *tex)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		bounds[2];

	get_draw_bounds(w->line_height, &bounds[0], &bounds[1]);
	step = (double)tex->height / w->line_height;
	tex_pos = (bounds[0] - WIN_HEIGHT / 2 + w->line_height / 2) * step;
	y = bounds[0];
	while (y < bounds[1])
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		put_pixel(g->display.img, x, y,
			get_texture_pixel(tex, w->tex_x, tex_y));
		y++;
	}
}

void	draw_wall(t_game *game, int x, t_wall *wall, int line_height)
{
	mlx_image_t	*texture;

	wall->line_height = line_height;
	texture = select_texture(&game->textures, wall->side,
			wall->step_x, wall->step_y);
	if (!texture)
		return ;
	draw_textured_stripe(game, x, wall, texture);
}
