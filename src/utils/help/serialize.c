/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:40:40 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 12:36:08 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

char **serializer(t_list *list)
{
    char **map2d;
    size_t length;
    size_t idx;
    
    if (!list)
        return (NULL);
    length = ft_lstsize(list) + 1;
    map2d = ft_calloc(length, sizeof(char *));
    if (!map2d)
        return (NULL);
    idx = 0;
    while (list)
    {
        map2d[idx] = ft_strdup((char *)list->content);
        if (!map2d[idx])
        {
            nullarr2d((void***)&map2d, length);
            return (NULL);
        }
        list = list->next;
        idx++;
    }
    return (map2d);
}
t_list *dserializer(char **arr)
{
    t_list *list;
    size_t idx;

    idx = 0;
    list = NULL;
    if (!arr || !*arr)
        return (NULL);
    
    while (arr[idx])
    {
        ft_lstadd_back(&list, ft_lstnew(ft_strdup(arr[idx])));
        idx++;
    }
    return (list);
}


