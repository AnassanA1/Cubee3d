/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:13:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 15:10:52 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void init_default(t_game *ref, int argc, char *argv[]);
void game_init(t_game**ref, int argc, char *argv[])
{
    *ref = ft_calloc(1, sizeof(t_game));
    if (!*ref)
    {
        ft_putendl_fd(strerror(errno), 2);
        exit(EXIT_FAILURE);
    }
    init_default(*ref, argc, argv);
    error_handler(&(*ref)->error);
    input_handler(*ref);
    map_handler(*ref);
    mostBeGood(ref);
}

static void init_default(t_game *ref, int argc, char *argv[])
{
    ref->argc = argc;
    ref->argv = argv;
    ref->scene.path = argv[1];
    ref->scene.fd = -1;
    ref->scene.rawmap = NULL;
}


