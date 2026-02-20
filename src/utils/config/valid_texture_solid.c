/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture_solid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:21:35 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 17:00:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static bool	valid_rgb(char *value);

void	valid_texture_solid(t_container *ref, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (*str)
	{
		str++;
		if (!is_space(*str))
		{
			tmp[i] = *str;
			i++;
		}
	}
	if (!valid_rgb(tmp))
	{
		free(tmp);
		tmp = find_replace(ERROR_GENERAL, "$MSG", ERROR_RGB, 0);
		ft_putstr_fd(tmp, STDERR_FILENO);
		free(tmp);
		ft_lstclear(&ref->datafile.map, free);
		ft_lstclear(&ref->datafile.map, free);
		exit(EXIT_FAILURE);
	}
	free(tmp);
}

static bool	valid_rgb(char *value)
{
	char	**rgb;
	size_t	len;
	size_t	idx;

	rgb = ft_split(value, ',');
	len = str2dlen(rgb);
	idx = 0;
	if (len != 3)
		return (nullarr2d((void ***)&rgb, len), false);
	while (idx < len)
	{
		if (ft_strlen(rgb[idx]) > 3 || !contain_only(rgb[idx], DECISET)
			|| ft_atoi(rgb[idx]) > 255)
			return (nullarr2d((void ***)&rgb, len), false);
		idx++;
	}
	return (nullarr2d((void ***)&rgb, len), true);
}
