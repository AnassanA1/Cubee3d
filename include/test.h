/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:37:40 by msidry            #+#    #+#             */
/*   Updated: 2026/01/19 16:15:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# define TEST_H

# define ECHO_MSG "\033[1;35mecho  :\033[0m \033[0;33m $message \033[0m\n"
# define DEBUG_MSG "\033[1;34mdebug :\033[0m \033[0;33m $message \033[0m :"

void	echo(char *message);
void	debug(char *lvl, char *message);
void	print_raw_map(t_list *map);
void	texture_info(t_texture *texture);
// char **remove_empty_str_at_end(char **arr);
void	print_map_grid(t_grid grid);
void	config_info(t_game *ref);

void	init_mlx(t_game *ref);

// typedef struct s_queue
// {
//     unsigned char content;
//     struct s_queue *next;
//     int x;
//     int y;
// } t_queue;

// t_queue *q_create(unsigned char c, int x, int y);
// void    q_delete(t_queue **node);
// t_queue *q_find(t_queue *queue, int x, int y);
// t_queue *q_last(t_queue *queue);
// int     q_pop(t_queue **queue, t_queue *out);
// void    q_push(t_queue **queue, t_queue *newq);
void	q_printQueue(t_queue *queue);
void	q_pushQueue(void);
void	q_popQueue(t_queue **queue);
// void    q_empty(t_queue **queue);
// bool    is_closed_bff(t_map *map, t_queue **queue);

#endif
