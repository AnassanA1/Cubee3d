/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:37:40 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 10:33:15 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# define TEST_H


#define ECHO_MSG "\033[1;35mecho :\033[0m \033[;33m $message \033[0m\n"

void echo(char *message);
void print_raw_map(t_list *map);
void texture_info(t_texture *texture);
void rgba_handler (t_error *error, t_texture *texture, char *rgbacolor);




#endif
