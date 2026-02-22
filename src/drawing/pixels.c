/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:16:27 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/22 19:17:17 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	int	index;
	int	*pixel;

	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return ;
	index = (y * img->width + x) * 4;
	pixel = (int *)(img->pixels + index);
	*pixel = color;
}

int	get_pixel(mlx_image_t *texture, int x, int y)
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
