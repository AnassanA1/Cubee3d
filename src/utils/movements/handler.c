/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 07:52:09 by msidry            #+#    #+#             */
/*   Updated: 2026/01/12 08:37:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	movement_handler(t_game *game)
{
	if (mlx_is_key_down(game->display.mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->display.mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->display.mlx, MLX_KEY_A))
		strafe_left(game);
	if (mlx_is_key_down(game->display.mlx, MLX_KEY_D))
		strafe_right(game);
	if (mlx_is_key_down(game->display.mlx, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->display.mlx, MLX_KEY_RIGHT))
		rotate_right(game);
}
