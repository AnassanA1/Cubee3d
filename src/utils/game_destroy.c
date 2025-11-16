/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:10:10 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 15:10:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void clean_scene(t_scene *scene);
static void clean_error(t_error *error);
void game_destroy(t_game **ref)
{
    // TODO: release resources !
    if (*ref)
    {
        clean_scene(&(*ref)->scene);
        clean_error(&(*ref)->error);
        free(*ref);
        *ref = NULL;
    }
}

static void clean_scene(t_scene *scene)
{
    if (scene->fd > -1)
        close(scene->fd);
    ft_lstclear(&scene->rawmap, free);
}
static void clean_error(t_error *error)
{
    if (error)
    {
        free(error->message);
        error->stat = 0;
    }
}
