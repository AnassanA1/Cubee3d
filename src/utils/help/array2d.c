/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:28:29 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 14:56:39 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void nullstr(char **str)
{
    if (str)
    {
        free(*str);
        *str = NULL;
    }
}

size_t str2dlen(char **str)
{
    size_t len;

    len = 0;
    if (!str)
        return (0);
    while (str[len])
        len++;
    return (len);
}

void nullarr2d(void ***ptr, size_t len)
{
    size_t idx;

    idx  = 0;
    if (!ptr || !*ptr)
        return ;
    if (ptr)
    {
        while (idx < len)
        {
            if ((*ptr)[idx])
                free((*ptr)[idx]);
            idx++;
        }
        free(*ptr);
        *ptr = NULL;
    }
}
