/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 07:52:09 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	movement_handler(t_container *ref)
{
	if (mlx_is_key_down(ref->display.mlx, MLX_KEY_W))
		move_forward(ref);
	if (mlx_is_key_down(ref->display.mlx, MLX_KEY_S))
		move_backward(ref);
	if (mlx_is_key_down(ref->display.mlx, MLX_KEY_A))
		strafe_left(ref);
	if (mlx_is_key_down(ref->display.mlx, MLX_KEY_D))
		strafe_right(ref);
	if (mlx_is_key_down(ref->display.mlx, MLX_KEY_LEFT))
		rotate_left(ref);
	if (mlx_is_key_down(ref->display.mlx, MLX_KEY_RIGHT))
		rotate_right(ref);
}
