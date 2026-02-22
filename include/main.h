/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:13:59 by msidry            #+#    #+#             */
/*   Updated: 2026/02/22 18:12:09 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// STD HEADERS
# include "../libs/mlx/MLX42.h"
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// CUSTOM HEADERS
# include "../libs/libft/libft.h"
# include "const.h"
# include "error.h"
# include "typedef.h"

// INIT GAME
void		game_init(t_container *ref);
void		game_destroy(t_container *ref);
void		game_run(t_container *ref);

// VALIDATION
void		input_validator(t_container *ref);

// MAP
void		map_handler(t_container *ref);
void		map_validator(t_container *ref);
void		empty_line(t_container *ref, char *line);
void		supported_line(t_container *ref, char *line);
void		one_direction(t_container *ref, char **arr);
void		closed_map(t_container *ref, t_map *map);
void		space_in_path(t_container *ref, t_map *map);

//  CONFIG
void		read_raw_config(t_container *ref);
void		split_raw_config(t_dfile *ref);
void		valid_textures(t_container *ref);
void		valid_texture_image(t_container *ref, char *str);
void		valid_texture_solid(t_container *ref, char *str);

// MLX
void		mlx_handler(t_container *ref, int action);

// TEXTURES
void		textures_handler(t_container *ref, int action);
mlx_image_t	*load_texture_image(t_container *ref, char *path);
t_uint		get_color(t_container *ref, char *target);
mlx_image_t	*get_texture_image(t_container *ref, char *target);

void		raycasting(t_container *ref);
void		cast_ray(t_container *ref, int x);
void		draw_floor_ceilling(t_container *ref);
void		draw_line(t_container *ref, t_ray *ray, t_vline *line);

// HELPER
char		*get_next_line(int fd);
char		*concat3(char *str1, char *str2, char *sep, int tofree);
char		*find_replace(char *src, char *target, char *new, int usefree);
int			is_space(int c);
void		nullstr(char **str);
		// free and set to null a string
size_t		str2dlen(char **str);
		// count length of arr of strings !
void		nullarr2d(void ***ptr, size_t len);
		// free and set to null a 2d array of size len
t_uint		rgbatoint(char *rgba);
		// converte rgba string to t_uint example: 255,255,255,255 to ~0
t_uint		match_count(char *str, unsigned char c);
		// count duplicate of char in string !
bool		contain_only(char *str, char *set);
			// check if string composed only of set;
char		*capitalize(const char *str);
t_uint		hexatoint(char *hexacolor);
		// converte hexa string to t_uint example: #FFFFFF to ~0
char		**serializer(t_list *list);
t_list		*dserializer(char **arr);
char		**trim_tail_empty(char **arr);
void		transform(char *str, const char *set, int c);
void		*ft_realloc(void *ptr, size_t oldsize, size_t newsize);
char		*normalize(char *str, size_t newsize, unsigned char toapp);
void		**alloc2darr(size_t elem, size_t items, size_t itemsize);

// movements.c
void		movement_handler(t_container *game);
void		move_forward(t_container *game);
void		move_backward(t_container *game);
void		rotate_left(t_container *game);
void		rotate_right(t_container *game);
void		strafe_right(t_container *game);
void		strafe_left(t_container *game);

// main

void		game_loop(void *param);
// drawing.c
//void		put_pixel(mlx_image_t *img, int x, int y, int color);
void		draw_floor_ceilling(t_container *game);
// int		 get_wall_color(t_textures *txt, int side, int step_x, int step_y);

// raycasting.c
void		raycasting(t_container *game);
void		cast_ray(t_container *game, int x);

// dda.c
void		init_dda(t_container *ref, t_ray *ray);
void		performing_dda(t_container *game, t_ray *ray);
// double  get_perpendular(t_container *game, t_ray *ray, t_wall *wall);
double		get_perpendular(t_wall *wall, t_dda *data);
// void draw_wall(t_container *game, int x, t_wall *wall, t_ray *ray);
int			calculate_line_height(double perp_wall_dist, int height);

// QUEUE
t_queue		*q_create(unsigned char c, int x, int y);
void		q_delete(t_queue **node);
t_queue		*q_find(t_queue *queue, int x, int y);
t_queue		*q_last(t_queue *queue);
int			q_pop(t_queue **queue, t_queue *out);
void		q_push(t_queue **queue, t_queue *newq);
void		q_empty(t_queue **queue);
bool		is_closed_bff(t_map *map, t_queue **queue);
bool		is_nospace_bff(t_map *map, t_queue **queue);

#endif
