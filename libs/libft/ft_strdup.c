/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 03:17:45 by msidry            #+#    #+#             */
/*   Updated: 2024/10/30 03:38:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	bytes;
	size_t	index;

	bytes = ft_strlen(str) + 1;
	ptr = malloc(sizeof(char) * bytes);
	if (!ptr)
		return (0);
	index = 0;
	while (index < bytes)
	{
		ptr[index] = str[index];
		index++;
	}
	return (ptr);
}
