/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:47:54 by msidry            #+#    #+#             */
/*   Updated: 2025/11/15 13:18:34 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	while (s1[start] && ft_contain(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_contain(set, s1[end - 1]))
		end--;
	ptr = malloc(sizeof(char) * (end - start) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s1[start], end - start + 1);
	return (ptr);
}
