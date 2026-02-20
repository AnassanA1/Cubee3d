/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:03:29 by msidry            #+#    #+#             */
/*   Updated: 2026/02/19 11:30:27 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	move_forward(t_container *ref)
{
	double	new_x;
	double	new_y;

	new_x = ref->player.pos.x + ref->player.dir.x * MOVE_SPEED;
	new_y = ref->player.pos.y + ref->player.dir.y * MOVE_SPEED;
	if (ref->map.map2d[(int)ref->player.pos.y][(int)new_x] != '1')
		ref->player.pos.x = new_x;
	if (ref->map.map2d[(int)new_y][(int)ref->player.pos.x] != '1')
		ref->player.pos.y = new_y;
}

void	move_backward(t_container *ref)
{
	double	new_x;
	double	new_y;

	new_x = ref->player.pos.x - ref->player.dir.x * MOVE_SPEED;
	new_y = ref->player.pos.y - ref->player.dir.y * MOVE_SPEED;
	if (ref->map.map2d[(int)ref->player.pos.y][(int)new_x] != '1')
		ref->player.pos.x = new_x;
	if (ref->map.map2d[(int)new_y][(int)ref->player.pos.x] != '1')
		ref->player.pos.y = new_y;
}

void	strafe_left(t_container *ref)
{
	double	new_x;
	double	new_y;

	new_x = ref->player.pos.x - ref->player.dir.y * MOVE_SPEED;
	new_y = ref->player.pos.y + ref->player.dir.x * MOVE_SPEED;
	if (ref->map.map2d[(int)ref->player.pos.y][(int)new_x] != '1')
		ref->player.pos.x = new_x;
	if (ref->map.map2d[(int)new_y][(int)ref->player.pos.x] != '1')
		ref->player.pos.y = new_y;
}

void	strafe_right(t_container *ref)
{
	double	new_x;
	double	new_y;

	new_x = ref->player.pos.x + ref->player.dir.y * MOVE_SPEED;
	new_y = ref->player.pos.y - ref->player.dir.x * MOVE_SPEED;
	if (ref->map.map2d[(int)ref->player.pos.y][(int)new_x] != '1')
		ref->player.pos.x = new_x;
	if (ref->map.map2d[(int)new_y][(int)ref->player.pos.x] != '1')
		ref->player.pos.y = new_y;
}
