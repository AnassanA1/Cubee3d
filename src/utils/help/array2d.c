/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:28:29 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 12:40:17 by msidry           ###   ########.fr       */
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

char **trim_tail_empty(char **arr)
{
    ssize_t len;
    char **newarr;
    ssize_t idx;

    if (!arr || !*arr)
        return (NULL);
    len = (ssize_t)str2dlen(arr) - 1;
    while (len >= 0 && ft_strlen(arr[len]) == 0)
        len--;
    if (len < 0)
        return (NULL);    
    newarr = ft_calloc(len + 2, sizeof(char *));
    if (!newarr)
        return (NULL);
    idx = -1;
    while (++idx <= len)
    {
        newarr[idx] = ft_strdup(arr[idx]);
        if (!newarr[idx])
        {
            nullarr2d((void ***)&newarr, idx);
            return (NULL);
        }       
    }
    return (newarr);  
}
