/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:14:39 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 17:00:58 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static void	check_configuration_count(t_container *ref);
static void	should_contain_one(t_container *ref, char *current);
static void	valid_prefix(t_container *ref, char *str);

void	valid_textures(t_container *ref)
{
	t_list	*current;
	char	*str;

	check_configuration_count(ref);
	current = ref->datafile.config;
	while (current)
	{
		str = (char *)current->content;
		valid_prefix(ref, str);
		if (str[0] == 'C' || str[0] == 'F')
			valid_texture_solid(ref, str);
		else
			valid_texture_image(ref, str);
		current = current->next;
	}
}

static void	check_configuration_count(t_container *ref)
{
	char	*tmp;
	t_list	*current;

	current = ref->datafile.config;
	if (!current || ft_lstsize(current) < 6)
	{
		tmp = find_replace(ERROR_GENERAL, "$MSG", EMPTY_CONF, 0);
		ft_putstr_fd(tmp, STDERR_FILENO);
		free(tmp);
		ft_lstclear(&ref->datafile.map, free);
		exit(EXIT_FAILURE);
	}
	while (current)
	{
		should_contain_one(ref, (char *)current->content);
		current = current->next;
	}
}

static void	should_contain_one(t_container *ref, char *current)
{
	t_list	*head;
	char	*tmp;
	int		count;

	count = 0;
	head = ref->datafile.config;
	while (head)
	{
		tmp = (char *)head->content;
		if (tmp[0] == current[0])
			count++;
		head = head->next;
	}
	if (count != 1)
	{
		if (count == 0)
			tmp = find_replace(ERROR_GENERAL, "$MSG", ERROR_MISSING, 0);
		else
			tmp = find_replace(ERROR_GENERAL, "$MSG", ERROR_DUP, 0);
		ft_putstr_fd(tmp, STDERR_FILENO);
		free(tmp);
		ft_lstclear(&ref->datafile.config, free);
		ft_lstclear(&ref->datafile.map, free);
		exit(EXIT_FAILURE);
	}
}

static void	valid_prefix(t_container *ref, char *str)
{
	char	*tmp;
	bool	valid_format;

	valid_format = false;
	if ((str[0] == 'F' || str[0] == 'C'))
	{
		if (is_space(str[1]))
			valid_format = true;
	}
	else
	{
		if (is_space(str[2]))
			valid_format = true;
	}
	if (!valid_format)
	{
		tmp = find_replace(ERROR_GENERAL, "$MSG", ERROR_SPACE, 0);
		ft_putstr_fd(tmp, STDERR_FILENO);
		free(tmp);
		ft_lstclear(&ref->datafile.map, free);
		exit(EXIT_FAILURE);
	}
}
