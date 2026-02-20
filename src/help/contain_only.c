/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain_only.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:23:52 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:04:05 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

bool	contain_only(char *str, char *set)
{
	int	idx;

	if (!str || !set)
		return (false);
	while (*str)
	{
		idx = -1;
		while (set[++idx])
		{
			if (*str == set[idx])
				break ;
		}
		if (*str != set[idx])
			return (false);
		str++;
	}
	return (true);
}
