/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_last.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:00:04 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:15 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_queue	*q_last(t_queue *queue)
{
	if (!queue)
		return (NULL);
	while (queue)
	{
		if (!queue->next)
			break ;
		queue = queue->next;
	}
	return (queue);
}
