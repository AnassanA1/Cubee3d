/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:28:09 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 13:42:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


bool init_error(t_error *ref)
{
    if (ref)
    {
        setStat(ref, 0);
        setError(ref, NULL);
        return (false);
    }
    return (true);
}

void setError(t_error *error, char *msg)
{
    if (!error)
        return ;
    free(error->message);
    if (!msg)
        error->message = NULL;
    else 
        error->message = ft_strdup(msg);
}
void setStat(t_error *error, int stat)
{
    if (!error)
        return ;
    error->stat = stat;
}

int what(t_error *error)
{
    if (error->stat)
        putError(error->message);
    return (error->stat);
}
void putError(char *msg)
{
    ft_putendl_fd(msg, 2);
}
