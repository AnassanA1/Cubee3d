/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture_solid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:21:35 by msidry            #+#    #+#             */
/*   Updated: 2026/02/22 11:33:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	parse_number(const char **s);
static int	is_valid_rgb(const char *s);

void	valid_texture_solid(t_container *ref, char *str)
{
	char	*tmp;

	if (!is_valid_rgb(str + 1))
	{
		tmp = find_replace(ERROR_GENERAL, "$MSG", ERROR_RGB, 0);
		ft_putstr_fd(tmp, STDERR_FILENO);
		free(tmp);
		ft_lstclear(&ref->datafile.map, free);
		ft_lstclear(&ref->datafile.map, free);
		exit(EXIT_FAILURE);
	}
}

static int	is_valid_rgb(const char *s)
{
	if (!parse_number(&s))
		return (0);
	while (is_space(*s))
		s++;
	if (*s++ != ',')
		return (0);
	if (!parse_number(&s))
		return (0);
	while (is_space(*s))
		s++;
	if (*s++ != ',')
		return (0);
	if (!parse_number(&s))
		return (0);
	while (is_space(*s))
		s++;
	return (*s == '\0');
}

static int	parse_number(const char **s)
{
	int	num;
	int	digits;

	num = 0;
	digits = 0;
	while (is_space(**s))
		(*s)++;
	while (ft_isdigit(**s))
	{
		num = num * 10 + (**s - '0');
		digits++;
		if (num > 255)
			return (0);
		(*s)++;
	}
	if (digits == 0)
		return (0);
	return (1);
}
