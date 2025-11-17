/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:15:26 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 15:40:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

t_uint match_count(char *str, unsigned char c)
{
    t_uint count;

    count = 0;
    if (!str)
        return (0);
    while (*str)
    {
        if (*str == c)
            count++;
        str++;
    }
    if (*str == c)
        count++;
    return (count);
}
