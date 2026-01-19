/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:06:29 by msidry            #+#    #+#             */
/*   Updated: 2026/01/12 08:07:48 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	game_loop(void *param)
{
	movement_handler((t_game *)param);
	raycasting((t_game *)param);
}