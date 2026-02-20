/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capitalize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:22:20 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:04:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	*capitalize(const char *str)
{
	int		idx;
	char	*result;

	if (!str)
		return (NULL);
	idx = 0;
	result = ft_strdup(str);
	while (result[idx])
	{
		if (ft_isalpha(result[idx]))
			result[idx] = ft_toupper(result[idx]);
		idx++;
	}
	return (result);
}
