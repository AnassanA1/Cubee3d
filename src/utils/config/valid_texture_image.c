/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:21:53 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 02:01:16 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	valid_texture_image(t_container *ref, char *str)
{
	char	*file;
	int		fd;
	char	*tmp;

	file = ft_strtrim(str + 2, SPACES);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		tmp = find_replace(ERROR_FILE, "$FILE", file, 0);
		ft_putstr_fd(tmp, STDERR_FILENO);
		free(tmp);
		free(file);
		ft_lstclear(&ref->datafile.config, free);
		ft_lstclear(&ref->datafile.map, free);
		exit(EXIT_FAILURE);
	}
	free(file);
	close(fd);
}
