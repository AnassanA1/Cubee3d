/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:28:09 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 15:14:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


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

int getStat(t_error *error)
{
    return (error->stat);
}

char *getError(t_error *error)
{
    return (error->message);
}
void putError(char *msg)
{
    ft_putendl_fd(msg, 2);
}
