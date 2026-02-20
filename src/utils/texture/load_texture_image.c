/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:48:27 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 02:11:28 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

mlx_image_t	*load_texture_image(t_container *ref, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(ref->display.mlx, texture);
	free(texture->pixels);
	free(texture);
	return (image);
}
