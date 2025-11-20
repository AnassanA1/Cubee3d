/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:52:26 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 16:03:14 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

void  transform(char *str, const char *set, int c)
{
    size_t idx;

    if (!str || !set)
        return ;
    while (*str)
    {
        idx = 0;
        while (set[idx])
        {
            if (*str == set[idx])
            {
                *str = c;
                break;
            }
            idx++;
        }
        str++;
    }
}
