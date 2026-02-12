/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:32:59 by msidry            #+#    #+#             */
/*   Updated: 2026/02/12 11:17:32 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static bool validArgc(int argc);
static bool validExtension(char *file);
static bool validFile(char *file);

void input_validator(int argc, char **argv)
{
    validArgc(argc);
    validExtension(argv[1]);
    validFile(argv[1]);
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

static bool validFile(char *file)
{
    char *message;
    char *tmp;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        message = concat3(file, strerror(errno), ": ", 0);
        tmp = find_replace(ERROR_GENERAL, "$MSG", message, 0);
        ft_putstr_fd(tmp, 2);
        free(message);
        free(tmp);
        exit(EXIT_FAILURE);
        return (false);
    }
    close(fd);
    return (true);
}

static bool validExtension(char *file)
{
    char *extension;
    char *tmp;

    extension = ft_strrchr(file, '.');
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
