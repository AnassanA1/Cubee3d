/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_raw_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:19:47 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 14:03:34 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static bool	match_conf(char *rawline);
static bool	all_space(char *str);

void	split_raw_config(t_dfile *ref)
{
	t_list	*current;
	char	*str;

	if (!ref->rawdata)
		return ;
	current = ref->rawdata;
	while (current)
	{
		if (match_conf((char *)current->content))
		{
			str = ft_strtrim((char *)current->content, SPACES);
			ft_lstadd_back(&ref->config, ft_lstnew(str));
		}
		else if (!all_space((char *)current->content))
			break ;
		current = current->next;
	}
	while (current)
	{
		str = ft_strtrim((char *)current->content, "\n");
		ft_lstadd_back(&ref->map, ft_lstnew(str));
		current = current->next;
	}
	ft_lstclear(&ref->rawdata, free);
}

static bool	match_conf(char *rawline)
{
	char	*idfs[7];
	int		i;

	i = -1;
	while (is_space(*rawline))
		rawline++;
	idfs[0] = NORTH;
	idfs[1] = SOUTH;
	idfs[2] = WEST;
	idfs[3] = EAST;
	idfs[4] = SKY;
	idfs[5] = FLOOR;
	idfs[6] = NULL;
	while (idfs[++i])
	{
		if (!ft_strncmp(idfs[i], rawline, ft_strlen(idfs[i])))
			return (true);
	}
	return (false);
}

static bool	all_space(char *str)
{
	char	*tmp;

	tmp = ft_strtrim(str, SPACES);
	if (!tmp || !*tmp)
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	return (false);
}
