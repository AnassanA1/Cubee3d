/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:01:47 by msidry            #+#    #+#             */
/*   Updated: 2026/02/21 14:45:53 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_uint	rgbatoint(char *rgbacolor)
{
	t_uint	rgba[3];
	char	**values;
	size_t	idx;
	size_t	length;

	idx = 0;
	values = ft_split(rgbacolor, ',');
	length = str2dlen(values);
	while (idx < length)
	{
		rgba[idx] = ft_atoi(values[idx]);
		idx++;
	}
	nullarr2d((void ***)&values, length);
	return (0xFF << 24 | (rgba[0] << 16) | (rgba[1] << 8) | (rgba[2]));
}