/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:42:15 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 13:43:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static bool validArgc(t_game *game);
static bool validFile(t_game *game);
static bool validExtension(t_game *game);

void input_validator(t_game *game)
{
    validCallback callbacks[4];
    size_t idx;

    idx = -1;
    callbacks[0] = validArgc;
    callbacks[1] = validExtension;
    callbacks[2] = validFile;
    callbacks[3] = NULL;
    while (callbacks[++idx])
    {
        if (callbacks[idx](game) == false)
            return; 
    }
}

static bool validArgc(t_game *game)
{
    if (!isAllOk(game))
        return (false);
    if(game->argc != ARGS)
    {
        setError(&game->error, BAD_ARGC);
        setStat(&game->error, 2);
        return (false);
    }
    return (true);
}

static bool validFile(t_game *game)
{
    char *message;
    char *tmp;

    if (!isAllOk(game))
        return (false);
    game->scene.fd = open(game->scene.path, O_RDONLY);
    if (game->scene.fd < 0)
    {
        message = concat3(game->scene.path, strerror(errno), ":", 0);
        printf("%s\n", message);
        tmp = find_replace(ERROR_GENERAL, "$MSG", message, 0);
        setError(&game->error, tmp);
        setStat(&game->error, errno);
        free(message);
        free(tmp);
        return (false);
    }
    return (true);
}

static bool validExtension(t_game *game)
{
    char *extension;
    char *tmp;

    if (!isAllOk(game))
        return (false);
    if (!game->argv[1][0])
    {
        setError(&game->error, BAD_FEMPTY);
        setStat(&game->error, 2);
        return (false);
    }
    extension = ft_strchr(game->scene.path, '.');
    if (!extension || ft_strncmp(EXTENSION, extension, ft_strlen(EXTENSION)))
    {
        tmp = find_replace(ERROR_GENERAL, "$MSG", ERROR_EXTA, 0);
        setError(&game->error, tmp);
        setStat(&game->error, 2);
        free(tmp);
        return (false);
    }
    return (true);
}
