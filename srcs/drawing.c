#include "../includes/cub3d.h"

void    put_pixel(mlx_image_t *img, int x, int y, int color)
{
    int index;

    if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
        return ;
    
    index = (y * img->width + x) * 4; // to find the correct pixel position * 4 (RGBA)
    img->pixels[index] = (color >> 16) & 0xFF; // Red component
    img->pixels[index + 1] = (color >> 8) & 0xFF; // Green component
    img->pixels[index + 2] = color & 0xFF; // Blue component
    img->pixels[index + 3] = 0xFF; // Alpha component
}

int	get_wall_color(int side, int step_x, int step_y)
{
	if (side == 0)
	{
		if (step_x > 0)
			return (0x8B4513);
		else
			return (0xA0522D);
	}
	else
	{
		if (step_y > 0)
			return (0xCD853F);
		else
			return (0xDEB887);
	}
}

void    draw_floor_ceilling(t_game *game)
{
    int x;
    int y;
    int floor_color;
    int ceil_color;

    floor_color = (game->colors.floor_r << 16) | (game->colors.floor_g << 8) | (game->colors.floor_b);
	ceil_color = (game->colors.ceil_r << 16) | (game->colors.ceil_g << 8) | (game->colors.ceil_b);
    y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            if (y < WIN_HEIGHT / 2)
				put_pixel(game->img, x, y, ceil_color);
			else
				put_pixel(game->img, x, y, floor_color);
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
	color = get_wall_color(wall->side, wall->step_x, wall->step_y);
	y = draw_start;
	while (y < draw_end)
	{
		put_pixel(game->img, x, y, color);
		y++;
	}
}