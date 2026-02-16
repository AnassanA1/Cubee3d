/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allGood.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:17:13 by msidry            #+#    #+#             */
/*   Updated: 2026/02/16 10:39:15 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	mostBeGood(t_game **ref)
{
	int	exitCode;

	if (!ref || !*ref)
		exit(EXIT_FAILURE);
	exitCode = (*ref)->error.stat;
	if (exitCode)
	{
		putError(getError(&(*ref)->error));
		game_destroy(ref);
		exit(exitCode);
	}
}

bool	isAllOk(t_game *ref)
{
	if (!ref)
		return (false);
	return (ref->error.stat == 0);
}
