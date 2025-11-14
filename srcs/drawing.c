#include "../includes/cub3d.h"

void    put_pixel(mlx_image_t *img, int x, int y, int color)
{
    int index;

    if (x <= 0 || x > (int)img->width || y <= 0 || y > (int)img->height)
        return ;
    
    index = (y * img->width + x) * 4; // to find the correct pixel position * 4 (RGBA)
    img->pixels[index] = (color >> 16) & 0xFF; // Red component
    img->pixels[index + 1] = (color >> 8) & 0xFF; // Green component
    img->pixels[index + 2] = color & 0xFF; // Blue component
    img->pixels[index + 3] = 0xFF; // Alpha component
}

void    draw_floor_ceilling(t_game *game)
{
    int x;
    int y;
    int floor_color;
    int ceil_color;

    floor_color = (game->colors.floor_r >> 16) | (game->colors.floor_g >> 8) \
    | (game->colors.floor_b); 
    ceil_color = game->colors.ceil_r;
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

