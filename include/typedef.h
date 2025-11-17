/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:14:02 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 14:05:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef unsigned int t_uint;

typedef struct s_error
{
    int stat;
    char *message;
} t_error;

typedef struct s_scene
{
    int fd;
    char *path;
    t_list *rawmap;
} t_scene;

typedef enum e_texture_type
{
    SOLID,
    IMAGE,
} t_txttype;

typedef struct s_texture
{
    t_txttype type;
    char *path;
    t_uint rgba;
} t_texture;

typedef struct s_game_textures
{
    t_texture sky_txt;
    t_texture south_txt;
    t_texture north_txt;
    t_texture east_txt;
    t_texture west_txt;
    t_texture floor_txt;
} t_gametxt;

typedef struct s_container
{
    int argc;
    char **argv;
    t_scene scene;
    t_error error;
    t_gametxt textures;
} t_game;

typedef bool(*validCallback)(t_game *game);
typedef void (*callconfi)(t_error *err, t_gametxt *txt, char *ln);
typedef void (*callformat)(t_error *err, t_texture *, char *frmt);

#endif
