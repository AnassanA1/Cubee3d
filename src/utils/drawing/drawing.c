/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:23:09 by msidry            #+#    #+#             */
/*   Updated: 2026/01/17 11:53:53 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void    put_pixel(mlx_image_t *img, int x, int y, int color)
{
    int index;

    if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
        return ;
    index = (y * img->width + x) * 4; // to find the correct pixel position * 4 (RGBA)
    img->pixels[index] = (color >> 24) & 0xFF; // Red component
    img->pixels[index + 1] = (color >> 16) & 0xFF; // Green component
    img->pixels[index + 2] = (color >> 8)& 0xFF; // Blue component
    img->pixels[index + 3] = color & 0xFF; // Alpha component
}

int	get_wall_color(t_textures *txt, int side, int step_x, int step_y)
{
	(void)txt;
	if (side == 0)
	{
		if (step_x > 0)
			return (0xFF0000FF);
		else
			return (0xFFFF00FF);
	}
	else
	{
		if (step_y > 0)
			return (0x00FFFFFF);
		else
			return (0xFF00FFFF);
	}
}

void    draw_floor_ceilling(t_game *game)
{
    int x;
    int y;
	y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            if (y < WIN_HEIGHT / 2)
				put_pixel(game->display.img, x, y, game->textures.sky_txt.texture.rgba);
			else
				put_pixel(game->display.img, x, y, game->textures.floor_txt.texture.rgba);
            x++;
        }
        y++;
    }
}



 void	draw_wall(t_game *game, int x, t_wall *wall, int line_height)
{
	int	draw_start;
	int	draw_end;
	int	y;
	int	color;

	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	color = get_wall_color(&game->textures, wall->side, wall->step_x, wall->step_y);
	y = draw_start;
	while (y < draw_end)
	{
		put_pixel(game->display.img, x, y, color);
		y++;
	}
}


