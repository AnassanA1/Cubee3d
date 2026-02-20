/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 02:12:54 by anasszgh          #+#    #+#             */
/*   Updated: 2026/02/20 14:03:23 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	init_mlx(t_container *ref);
static void	init_img(t_container *ref);
static void	bind_img(t_container *ref);
static void	destroy_mlx(t_container *ref);

void	mlx_handler(t_container *ref, int action)
{
	if (action)
	{
		init_mlx(ref);
		init_img(ref);
		bind_img(ref);
	}
	else
		destroy_mlx(ref);
}

static void	init_mlx(t_container *ref)
{
	ref->display.mlx = mlx_init(ref->display.width, ref->display.height,
			WIN_TITLE, true);
	if (!ref->display.mlx)
	{
		ft_putstr_fd(ERROR_MLX, STDERR_FILENO);
		game_destroy(ref);
		exit(EXIT_FAILURE);
	}
}

static void	init_img(t_container *ref)
{
	ref->display.img = mlx_new_image(ref->display.mlx, ref->display.width,
			ref->display.height);
	if (!ref->display.img)
	{
		ft_putstr_fd(ERROR_MLX, STDERR_FILENO);
		game_destroy(ref);
		mlx_terminate(ref->display.mlx);
		exit(EXIT_FAILURE);
	}
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

static void	destroy_mlx(t_container *ref)
{
	if (ref->display.img)
	{
		mlx_delete_image(ref->display.mlx, ref->display.img);
		ref->display.img = NULL;
	}
	if (ref->display.mlx)
	{
		mlx_terminate(ref->display.mlx);
		ref->display.mlx = NULL;
	}
}
