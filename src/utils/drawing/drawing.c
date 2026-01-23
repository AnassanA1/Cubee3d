/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:23:09 by msidry            #+#    #+#             */
/*   Updated: 2026/01/22 06:21:47 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	int	index;

	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return ;
	index = (y * img->width + x) * 4;
	img->pixels[index] = (color >> 24) & 0xFF;
	img->pixels[index + 1] = (color >> 16) & 0xFF;
	img->pixels[index + 2] = (color >> 8) & 0xFF;
	img->pixels[index + 3] = color & 0xFF;
}

int	get_texture_pixel(mlx_image_t *texture, int x, int y)
{
	int	idx;
	int	r;
	int	g;
	int	b;

	if (!texture || x < 0 || x >= (int)texture->width
		|| y < 0 || y >= (int)texture->height)
		return (0xFF00FFFF);
	idx = (y * texture->width + x) * 4;
	r = texture->pixels[idx];
	g = texture->pixels[idx + 1];
	b = texture->pixels[idx + 2];
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

mlx_image_t	*select_texture(t_textures *txt, int side, int sx, int sy)
{
	if (side == 0)
	{
		if (sx > 0)
			return (txt->east_txt.texture.img_texture.txt);
		else
			return (txt->west_txt.texture.img_texture.txt);
	}
	else
	{
		if (sy > 0)
			return (txt->south_txt.texture.img_texture.txt);
		else
			return (txt->north_txt.texture.img_texture.txt);
	}
}

void	draw_floor_ceilling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel(game->display.img, x, y,
					game->textures.sky_txt.texture.rgba);
			else
				put_pixel(game->display.img, x, y,
					game->textures.floor_txt.texture.rgba);
			x++;
		}
		y++;
	}
}