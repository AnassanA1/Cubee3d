/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:54:25 by msidry            #+#    #+#             */
/*   Updated: 2025/11/21 10:29:24 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static bool empty_line(t_error *error, char *line);
static bool supported_line(t_error *error,char *line);
//static bool closed_line(t_error *error, char *line, size_t curr, size_t size);
static bool one_direction(t_error *error, char **arr);

void map_validator(t_game *ref)
{
    size_t  idx;
    size_t  len;
    char    **lines;

    idx = 0;
    if (!isAllOk(ref))
        return ;
    lines = ref->map.map2d;
    len = str2dlen(lines);
    while (lines[idx])
    {
        
        if (empty_line(&ref->error, lines[idx]))
            return ;
        if (!one_direction(&ref->error, lines))
            return ;
        if (!supported_line(&ref->error, lines[idx]))
            return ;
        //if (!closed_line(&ref->error, lines[idx], idx, len))
        //    return ;
        idx++;
    }    
}


// static bool closed_line(t_error *error, char *line, size_t curr, size_t size)
// {
//     size_t idx;

//     if (curr == 0 || curr == size)
//     {
//         if (!contain_only(line, "1"))
//         {
//             setError(error, BAD_S_LINE);
//             setStat(error, EXIT_FAILURE);
//             return (false);
//         }
//         return (true);
//     }
//     idx = ft_strlen(line);
//     if (*line != '1' || line[idx - 1] != '1')
//     {
//         setError(error, BAD_S_LINE);
//         setStat(error, EXIT_FAILURE);
//         return (false);
//     }
//     return (true);
// }


static bool empty_line(t_error *error, char *line)
{
    char *err;

    if (contain_only(line, SPACES))
    {
        if (error)
        {
            err = find_replace(ERROR_GENERAL, "$MSG", BAD_E_LINE, 0);
            setError(error, err);
            setStat(error, EXIT_FAILURE);
            nullstr(&err);
        }
        return (true);  
    }
    return (false);
}

static bool supported_line(t_error *error,char *line)
{
    char *err;
    if (!contain_only(line, MAPSET))
    {
        err = find_replace(ERROR_GENERAL, "$MSG", BAD_C_LINE, 0);
        setError(error, BAD_C_LINE);
        setStat(error, EXIT_FAILURE);
        nullstr(&err);
        return (false);
    }
    return (true);
}



static bool one_direction(t_error *error, char **arr)
{
    size_t idx;
    size_t jdx;
    size_t count;

    idx = -1;
    count = 0;
    while (arr && arr[++idx])
    {
        jdx = -1;
        while (arr[idx][++jdx])
        {
            if (match_count("NEWS", arr[idx][jdx]))
                count++;
        }
    }
    if (count != 1)
    {
        setError(error, find_replace(ERROR_GENERAL, "$MSG", BAD_D_LINE, 0));
        setStat(error, EXIT_FAILURE);
    }
    return (count == 1);
}
