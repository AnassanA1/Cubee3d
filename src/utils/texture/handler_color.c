/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:41:23 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 16:55:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


static bool valid_rgba(char *color);
//static bool valid_hexa(char *color);

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
    texture->rgba = rgbatoint(color);
    nullstr(&color);
}


static bool valid_rgba(char *color)
{
    if (!color)
        return (false);
    if (match_count(color, ',') != 3)
        return (false);
    if (!contain_only(color, DECISET))
        return (false);
    return (true);
}




// void hexa_handler(t_error *error, t_texture *texture, char *rgbacolor)
// {
//     char *color;

//     if (*rgbacolor == '(' && rgbacolor[ft_strlen(rgbacolor) - 1] == ')')
//         color = ft_substr(rgbacolor, 1, ft_strlen(&rgbacolor[1]) - 1);
//     else
//         color = ft_strdup(rgbacolor);
//     if (!valid_rgba(color))
//     {
//         setError(error, ERROR_RGBA);   
//         setStat(error, EXIT_FAILURE);
//         nullstr(&color);
//     }
//     texture->type = SOLID;
//     texture->rgba = rgbatoint(color);
//     nullstr(&color);
// }

// static bool valid_hexa(char *color)
// {
//     if (!color)
//         return (false);
//     if (match_count(color, ',') < 2)
//         return (false);
//     if (!contain_only(color, DECISET))
//         return (false);
//     return (true);
// }
