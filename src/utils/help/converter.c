/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:01:47 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 16:30:28 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

t_uint rgbatoint(char *rgbacolor)
{
    t_uint rgba[4];
    char **values;
    size_t length;
    size_t idx;
    char ***ptr;
    
    if (!rgbacolor)
        return (0);
    values = ft_split(rgbacolor, ',');
    length = str2dlen(values);
    idx  = -1;
    if (length < 3)
        rgba[++idx] = 0xFF;
    while (++idx < 4)
    {
        rgba[idx] = ft_atoi(values[idx]);
        if (rgba[idx] > 255 || rgba[idx] < 0)
            rgba[idx] = rgba[idx] & 0xFF;
    }
    ptr = &values;
    nullarr2d((void ***)ptr, length);
    return ((rgba[0] << 24) | (rgba[1] << 16) |(rgba[2] << 8) | rgba[3]);
}
