/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_last.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:34:07 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/16 10:34:08 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

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
