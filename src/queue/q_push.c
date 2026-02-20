/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:59:48 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:21 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	q_push(t_queue **queue, t_queue *item)
{
	t_queue	*last;

	if (!queue || !item)
		return ;
	if (!*queue)
	{
		*queue = item;
		return ;
	}
	last = q_last(*queue);
	if (last)
		last->next = item;
}
