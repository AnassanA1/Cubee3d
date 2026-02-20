/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_crud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:59:44 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:09 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_queue	*q_create(unsigned char c, int x, int y)
{
	t_queue	*newq;

	newq = ft_calloc(1, sizeof(t_queue));
	if (!newq)
		return (NULL);
	newq->content = c;
	newq->x = x;
	newq->y = y;
	newq->next = NULL;
	return (newq);
}

void	q_delete(t_queue **node)
{
	if (!node || !*node)
		return ;
	memset(*node, 0, sizeof(t_queue));
	free(*node);
	*node = NULL;
}

void	q_empty(t_queue **queue)
{
	t_queue	out;

	while (q_pop(queue, &out))
		;
}
