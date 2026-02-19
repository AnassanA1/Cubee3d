/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:32:59 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 17:01:33 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static bool validArgc(int argc);
static bool validExtension(t_dfile *ref);
static bool validFile(t_dfile *ref);

void input_validator(t_container *ref)
{
    validArgc(ref->argc);
    validExtension(&ref->datafile);
    validFile(&ref->datafile);
}

static bool validArgc(int argc)
{
    if(argc != ARGS)
    {
        char    *message;
        if (argc != 1)
            message = find_replace(ERROR_GENERAL, "$MSG", BAD_ARGC, 0);
        else
            message = find_replace(ERROR_GENERAL, "$MSG", BAD_FEMPTY, 0);
        ft_putstr_fd(message, 2);
        free(message);
        exit(EXIT_FAILURE);
        return (false);
    }
    return (true);
}

static bool validFile(t_dfile *ref)
{
    char *message;
    char *tmp;

    ref->fd = open(ref->path, O_RDONLY);
    if (ref->fd < 0)
    {
        message = concat3(ref->path, strerror(errno), ": ", 0);
        tmp = find_replace(ERROR_GENERAL, "$MSG", message, 0);
        ft_putstr_fd(tmp, 2);
        free(message);
        free(tmp);
        exit(EXIT_FAILURE);
        return (false);
    }
    return (true);
}

static bool validExtension(t_dfile *ref)
{
    char *extension;
    char *tmp;

    extension = ft_strrchr(ref->path, '.');
    if (!extension || ft_strncmp(EXTENSION, extension, 5))
    {
        tmp = find_replace(ERROR_GENERAL, "$MSG", ERROR_EXTA, 0);
        ft_putstr_fd(tmp, 2);
        free(tmp);
        exit(EXIT_FAILURE);
        return (false);
    }
    return (true);
}
