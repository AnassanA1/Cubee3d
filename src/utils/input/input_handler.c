/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:32:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/16 14:05:57 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void input_handler(t_game *ref)
{
    if (!isAllOk(ref))
        return ;
    input_validator(ref);
    //TODO: check if all good !
}
