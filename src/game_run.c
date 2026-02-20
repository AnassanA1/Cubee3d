/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:54:13 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:06:06 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_container	*ref;

	ref = (t_container *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(ref->display.mlx);
}

void	game_run(t_container *ref)
{
	mlx_key_hook(ref->display.mlx, &key_hook, ref);
	mlx_loop_hook(ref->display.mlx, &game_loop, ref);
	mlx_loop(ref->display.mlx);
}
