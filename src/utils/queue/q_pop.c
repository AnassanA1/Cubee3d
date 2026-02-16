/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_pop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:33:56 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/16 10:33:57 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

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
