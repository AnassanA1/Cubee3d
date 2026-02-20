/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:51:41 by msidry            #+#    #+#             */
/*   Updated: 2026/02/20 13:53:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_GENERAL "\033[1;31mError: $MSG !\n\033[0m"
# define BAD_ARGC "Invalid argument count"
# define BAD_FEMPTY "Scene description file is mandatory"
# define EMPTY_MAP "Invalid empty configuration file"
# define EMPTY_CONF "Add {NO, SO, WE, EA, F, C} configuration at top of map"
# define ERROR_EXTA "Invalid file extension"
# define BAD_E_LINE "Empty Line within the map"
# define BAD_C_LINE "Map line should contain only {1, 0, E, W, S, N, ' '}"
# define BAD_D_LINE "Player has to face one direction {S, N, E, W}"
# define BAD_C_MAP "\033[1;31mError: Map is not closed with walls !\n\033[0m"
# define BAD_P_MAP "\033[1;31mError: Map has space in walkable path !\n\033[0m"
# define ERROR_MISSING "Missing textutes check {NO, SO, WE, EA, F, C}"
# define ERROR_DUP "Duplicate textutes check {NO, SO, WE, EA, F, C}"
# define ERROR_SPACE "Texture should be prefix {NO, F, ...} + space + value"
# define ERROR_TEXTURE_FILE "Invalid texture"
# define ERROR_RGB "Invalid rgb value it should be 0-255, 0-255, 0-255"
# define ERROR_MLX "\033[1;31mError: Unable to init mlx !\n\033[0m"
# define ERROR_LOAD_PNG "\033[1;31mError: Unable to load texture !\n\033[0m"
# define ERROR_FILE "\033[1;31mError: Invalid texture file `$FILE` !\n\033[0m"
#endif
