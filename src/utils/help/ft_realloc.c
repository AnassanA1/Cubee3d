/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:14:01 by msidry            #+#    #+#             */
/*   Updated: 2025/11/20 11:18:03 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void *ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
    void *newptr;

    newptr = ft_calloc(newsize, sizeof(char));
    if (!newptr)
        return (free(ptr), NULL);
    ft_memcpy(newptr, ptr, oldsize + 1);
    free(ptr);
    return (newptr);
}

