/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:01:29 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 14:56:42 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

char	*concat3(char *str1, char *str2, char *sep, int tofree)
{
	size_t	totlen;
	char	*result;

	totlen = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(sep);
	result = ft_calloc(totlen + 1, 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str1, ft_strlen(str1) + 1);
	ft_strlcpy(result + ft_strlen(result), sep, ft_strlen(sep) + 1);
	ft_strlcpy(result + ft_strlen(result), str2, ft_strlen(str2) + 1);
	if (tofree & 1)
		free(str1);
	if (tofree & 2)
		free(str2);
	if (tofree & 4)
		free(sep);
	return (result);
}
