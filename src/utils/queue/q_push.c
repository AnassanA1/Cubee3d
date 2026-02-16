/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:34:00 by azghibat          #+#    #+#             */
/*   Updated: 2026/02/16 10:34:01 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

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
