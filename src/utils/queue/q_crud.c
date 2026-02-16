/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_crud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:33:48 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/16 10:33:49 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

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
