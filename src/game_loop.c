/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:06:29 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:06:03 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	bind_img(t_container *ref);
void		mlx_auto_resize(int width, int height, void *param);

void	game_loop(void *param)
{
	t_container	*ref;

	ref = (t_container *)param;
	movement_handler(ref);
	mlx_resize_hook(ref->display.mlx, mlx_auto_resize, ref);
	draw_floor_ceilling((t_container *)param);
	raycasting((t_container *)param);
}

void	mlx_auto_resize(int width, int height, void *param)
{
	t_container	*ref;

	ref = (t_container *)param;
	mlx_delete_image(ref->display.mlx, ref->display.img);
	ref->display.height = height;
	ref->display.width = width;
	ref->display.img = mlx_new_image(ref->display.mlx, width, height);
	bind_img(ref);
}

static void	bind_img(t_container *ref)
{
	if (mlx_image_to_window(ref->display.mlx, ref->display.img, 0, 0) < 0)
	{
		ft_putstr_fd(ERROR_MLX, STDERR_FILENO);
		game_destroy(ref);
		mlx_terminate(ref->display.mlx);
		exit(EXIT_FAILURE);
	}
}
