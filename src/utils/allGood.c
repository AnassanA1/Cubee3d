/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isAllGood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:17:13 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 13:45:09 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void mostBeGood(t_game **ref)
{
    int exitCode;
    if (!ref || !*ref)
        exit(EXIT_FAILURE);
    exitCode = (*ref)->error.stat;
    if (exitCode)
    {
        what(&(*ref)->error);
        game_destroy(ref);
        exit(exitCode);
    }
}
bool isAllOk(t_game *ref)
{
    if (!ref)
        return(false);
    return (ref->error.stat == 0);
}
