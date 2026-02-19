/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:23:09 by msidry            #+#    #+#             */
/*   Updated: 2026/02/19 11:35:52 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void    put_pixel(mlx_image_t *img, int x, int y, int color)
{
    int index;
	int *pixel;

    if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
        return ;
    index = (y * img->width + x) * 4;
	pixel = (int *)(img->pixels + index);
	*pixel = color;
	//img->pixels[index + 3] = color >> 24 ; //alpha
    //img->pixels[index + 2] = (color >> 16) & 0xFF; // red component
    //img->pixels[index + 1] = (color >> 8) & 0xFF; // green component
    //img->pixels[index]= (color & 0xFF); // blue component
}


void    draw_floor_ceilling(t_container *ref)
{
    unsigned int  x;
    unsigned int  y;
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



//  void	draw_wall(t_container *ref, int x, t_wall *wall, int line_height)
// {
// 	int	draw_start;
// 	int	draw_end;
// 	int	y;
// 	int	color;

// 	draw_start = -line_height / 2 + ref->display.height / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	draw_end = line_height / 2 + ref->display.height / 2;
// 	if (draw_end >= ref->display.height)
// 		draw_end = ref->display.height - 1;
// 	color = get_wall_color(ref, wall->side, wall->step_x, wall->step_y);
// 	y = draw_start;
// 	while (y < draw_end)
// 	{
// 		put_pixel(ref->display.img, x, y, color);
// 		y++;
// 	}
// }


