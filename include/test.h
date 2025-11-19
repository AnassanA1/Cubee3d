/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:37:40 by msidry            #+#    #+#             */
/*   Updated: 2025/11/19 12:56:27 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# define TEST_H


#define ECHO_MSG "\033[1;35mecho  :\033[0m \033[0;33m $message \033[0m\n"
#define DEBUG_MSG "\033[1;34mdebug :\033[0m \033[0;33m $message \033[0m :"

void echo(char *message);
void debug(char *lvl, char *message);
void print_raw_map(t_list *map);
void texture_info(t_texture *texture);
//char **remove_empty_str_at_end(char **arr);
void print_map_grid(t_grid grid);
void config_info(t_game *ref);


#endif
