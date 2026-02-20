/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_pop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:59:53 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:18 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	q_pop(t_queue **queue, t_queue *out)
{
	t_queue	*tmp;

	if (!queue || !*queue || !out)
		return (0);
	tmp = *queue;
	out->content = tmp->content;
	out->x = tmp->x;
	out->y = tmp->y;
	out->next = NULL;
	*queue = tmp->next;
	free(tmp);
	return (1);
}
