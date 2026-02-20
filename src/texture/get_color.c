/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:27:16 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:31 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_uint	get_color(t_container *ref, char *target)
{
	if (*target == 'C')
		return (ref->txt_solid[0].rgb);
	return (ref->txt_solid[1].rgb);
}

mlx_image_t	*get_texture_image(t_container *ref, char *target)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		if (ref->txt_images[idx].key[0] == *target)
			return (ref->txt_images[idx].img);
		idx++;
	}
	return (ref->txt_images[0].img);
}
