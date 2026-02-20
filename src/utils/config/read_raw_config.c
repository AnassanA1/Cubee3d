/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:53:59 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 17:00:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void	read_raw_config(t_container *ref)
{
	char	*rawline;
	t_list	*node;
	char	*tmp;

	while (true)
	{
		rawline = get_next_line(ref->datafile.fd);
		if (!rawline)
			break ;
		node = ft_lstnew(ft_strtrim(rawline, "\n"));
		ft_lstadd_back(&ref->datafile.rawdata, node);
		free(rawline);
	}
	close(ref->datafile.fd);
	if (!ref->datafile.rawdata)
	{
		tmp = find_replace(ERROR_GENERAL, "$MSG", EMPTY_MAP, 0);
		ft_putstr_fd(tmp, STDERR_FILENO);
		free(tmp);
		exit(EXIT_FAILURE);
	}
}
