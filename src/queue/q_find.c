/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:59:57 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:13 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_queue	*q_find(t_queue *queue, int x, int y)
{
	if (!queue)
		return (NULL);
	while (queue)
	{
		if (queue->x == x && queue->y == y)
			return (queue);
		queue = queue->next;
	}
	return (NULL);
}
