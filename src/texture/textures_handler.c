/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:40:01 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:41 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void	init_textures(t_container *ref);
static void	handle_solid(t_container *ref, char *str);
static void	handle_image(t_container *ref, char *str);
static void	destroy_textures(t_container *ref);

void	textures_handler(t_container *ref, int action)
{
	if (action)
		init_textures(ref);
	else
		destroy_textures(ref);
}

static void	init_textures(t_container *ref)
{
	t_list	*curr;
	char	*str;

	curr = ref->datafile.config;
	while (curr)
	{
		str = (char *)curr->content;
		if (*str == 'F' || *str == 'C')
			handle_solid(ref, str);
		else
			handle_image(ref, str);
		curr = curr->next;
	}
}

static void	handle_solid(t_container *ref, char *str)
{
	if (*str == 'C')
	{
		ref->txt_solid[0].key = ft_strdup(SKY);
		ref->txt_solid[0].value = ft_strtrim(str + 1, SPACES);
		ref->txt_solid[0].rgb = rgbatoint(ref->txt_solid[0].value);
	}
	else
	{
		ref->txt_solid[1].key = ft_strdup(FLOOR);
		ref->txt_solid[1].value = ft_strtrim(str + 1, SPACES);
		ref->txt_solid[1].rgb = rgbatoint(ref->txt_solid[1].value);
	}
}

static void	handle_image(t_container *ref, char *str)
{
	int	idx;

	idx = 0;
	if (*str == 'S')
		idx = 1;
	else if (*str == 'E')
		idx = 2;
	else if (*str == 'W')
		idx = 3;
	ref->txt_images[idx].key = ft_substr(str, 0, 2);
	ref->txt_images[idx].value = ft_strtrim(str + 2, SPACES);
	ref->txt_images[idx].img = load_texture_image(ref,
			ref->txt_images[idx].value);
	if (!ref->txt_images[idx].img)
	{
		destroy_textures(ref);
		mlx_terminate(ref->display.mlx);
		game_destroy(ref);
		ft_putstr_fd(ERROR_LOAD_PNG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static void	destroy_textures(t_container *ref)
{
	int	idx;

	idx = 0;
	while (idx < 2)
	{
		nullstr(&ref->txt_solid[idx].key);
		nullstr(&ref->txt_solid[idx].value);
		idx++;
	}
	idx = 0;
	while (idx < 4)
	{
		nullstr(&ref->txt_images[idx].key);
		nullstr(&ref->txt_images[idx].value);
		ref->txt_images[idx].img = NULL;
		idx++;
	}
}
