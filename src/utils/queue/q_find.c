/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:33:53 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/16 10:33:54 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

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
