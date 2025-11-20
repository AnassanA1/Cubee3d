/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:09:35 by msidry            #+#    #+#             */
/*   Updated: 2025/11/20 11:06:19 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


char *normalize(char *str, size_t newsize, unsigned char toapp)
{
    char *newstr;
    size_t len;

    len = ft_strlen(str);
    if (len + 1 == newsize)
        return (str);
    newstr = ft_realloc(str, len , newsize + 1);
    if (!newstr)
        return (nullstr(&str), NULL);
    ft_memset(&newstr[len], toapp, newsize - len - 1);
    return (newstr);
}

