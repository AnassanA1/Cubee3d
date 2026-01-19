/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_texture_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:41:23 by msidry            #+#    #+#             */
/*   Updated: 2026/01/13 11:17:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


static bool valid_rgba(char *color);
static bool valid_hexa(char *color);
static char **split_trim(char *set, char sep, char *trimed);

void rgba_handler(t_error *error, t_texture *texture, char *rgbacolor)
{
    char *color;
    size_t len;

    while (is_space(*rgbacolor))
        rgbacolor++;
    len = ft_strlen(rgbacolor);
    if (len && *rgbacolor == '(' && rgbacolor[len - 1] == ')')
        color = ft_substr(rgbacolor, 1, ft_strlen(&rgbacolor[1]) - 1);
    else
        color = ft_strdup(rgbacolor);
    if (!valid_rgba(color))
    {
        setError(error, ERROR_FORMAT);   
        setStat(error, EXIT_FAILURE);
        nullstr(&color);
        return ;
    }
    texture->type = SOLID;
    texture->texture.rgba = rgbatoint(color);
    texture->is_set = true;
    nullstr(&color);
}


static bool valid_rgba(char *color)
{
    int idx;
    size_t len;
    len = 0;
    char **rgba;
    rgba = split_trim(color, ',', SPACES);
    if (!rgba)
        return (false);
    while (rgba[len])len++;
    idx = -1;
    while (rgba[++idx])
    {
        if (ft_strlen(rgba[idx]) > 3 || len != 4)
            return (nullarr2d((void ***)&rgba, len), false);
        if (!contain_only(rgba[idx], DECISET))
            return (nullarr2d((void ***)&rgba, len), false);
        if (ft_strlen(rgba[idx]) == 3 && ft_strncmp(rgba[idx], "255", 4) > 0)
            return (nullarr2d((void ***)&rgba, len), false);
    }
    return (nullarr2d((void ***)&rgba, idx), true);
}




void hexa_handler(t_error *error, t_texture *texture, char *hexacolor)
{
    char *color;
    size_t len;

    while (is_space(*hexacolor))
        hexacolor++;
    len = ft_strlen(hexacolor);
    if (!valid_hexa(hexacolor))
    {
        setError(error, ERROR_FORMAT);   
        setStat(error, EXIT_FAILURE);
        return ;
    }
    if (len == 6)
        color = concat3(capitalize(hexacolor), "FF", NULL, 1);
    else
        color = concat3(capitalize(hexacolor), NULL, NULL, 1);
    texture->type = SOLID;
    texture->texture.rgba = hexatoint(color);
    texture->is_set = true;
    nullstr(&color);
}

static bool valid_hexa(char *color)
{
    size_t len;

    if (!color)
        return (false);
    len = ft_strlen(color);
    if (len != 6 && len != 8)
        return (false);
    if (!contain_only(color, HEXASET))
        return (false);
    return (true);
}


static char **split_trim(char *set, char sep, char *trimed)
{
    char **result;
    char *tmp;
    int idx;
    size_t len;

    idx = 0;
    len = -1;
    if (!set || !*set || !trimed || match_count(set, ',') > 3)
        return (NULL);
    result = ft_split(set, sep);
    if (!result)
        return (NULL);
    while (result[++len])
        ;
    while (result[idx])
    {
        tmp = ft_strtrim(result[idx], trimed);
        if (!tmp || !*tmp)
            return (free(tmp), nullarr2d((void ***)&result, len), NULL);
        free(result[idx]);
        result[idx] = tmp;
        idx++;
    }
    return (result);
}
