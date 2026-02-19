/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:04:01 by msidry            #+#    #+#             */
/*   Updated: 2026/02/19 11:30:15 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	rotate_left(t_container *ref)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ref->player.dir.x;
	old_plane_x = ref->player.plane.x;
	
	ref->player.dir.x = ref->player.dir.x * cos(-ROT_SPEED) - \
		ref->player.dir.y * sin(-ROT_SPEED);
	ref->player.dir.y = old_dir_x * sin(-ROT_SPEED) + \
		ref->player.dir.y * cos(-ROT_SPEED);
	
	ref->player.plane.x = ref->player.plane.x * cos(-ROT_SPEED) - \
		ref->player.plane.y * sin(-ROT_SPEED);
	ref->player.plane.y = old_plane_x * sin(-ROT_SPEED) + \
		ref->player.plane.y * cos(-ROT_SPEED);
}

void	rotate_right(t_container *ref)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ref->player.dir.x;
	old_plane_x = ref->player.plane.x;
	
	ref->player.dir.x = ref->player.dir.x * cos(ROT_SPEED) - \
		ref->player.dir.y * sin(ROT_SPEED);
	ref->player.dir.y = old_dir_x * sin(ROT_SPEED) + \
		ref->player.dir.y * cos(ROT_SPEED);
	
	ref->player.plane.x = ref->player.plane.x * cos(ROT_SPEED) - \
		ref->player.plane.y * sin(ROT_SPEED);
	ref->player.plane.y = old_plane_x * sin(ROT_SPEED) + \
		ref->player.plane.y * cos(ROT_SPEED);
}