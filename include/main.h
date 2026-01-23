/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:13:59 by msidry            #+#    #+#             */
/*   Updated: 2026/01/22 13:02:14 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// STD HEADERS
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "../libs/mlx/MLX42.h"

// CUSTOM HEADERS
# include "../libs/libft/libft.h"
# include "typedef.h"
# include "error.h"
# include "const.h"
# include "test.h"

// INIT GAME 
void game_init(t_game **ref, int argc, char *argv[]);
void game_destroy(t_game **ref);

// ERROR HANDLING
void		setError(t_error *error, char *msg);
char        *getError(t_error *error);
void		setStat(t_error *error, int stat);
int         getStat(t_error *error);
void		putError(char *msg);

// VALIDATION
void		input_handler(t_game *ref);
void		mostBeGood(t_game **ref);
bool		isAllOk(t_game *ref);

// MAP && scene
void		map_handler(t_game *ref);
void        map_validator(t_game *ref);
void        normaize_width(t_map *map, unsigned char toapp);


//  CONFIG 
void        config_handler(t_game *ref);
void		read_raw_config(t_game *ref);
int         is_map_config(char *line);


// TEXTURES 
void	texture_handler(t_game *ref);
int		get_texture_pixel(mlx_image_t *texture, int x, int y);
void	calculate_tex_x(t_game *game, t_ray *ray, t_wall *wall);
mlx_image_t	*select_texture(t_textures *txt, int side, int sx, int sy);
// SETTERS FOR TEXTURES
void	set_south_texture(t_error *err, t_textures *textures, char *line);
void	set_north_texture(t_error *err, t_textures *textures, char *line);
void	set_east_texture(t_error *err, t_textures *textures, char *line);
void	set_west_texture(t_error *err, t_textures *textures, char *line);
void	set_sky_texture(t_error *err, t_textures *textures, char *line);
void	set_floor_texture(t_error *err, t_textures *textures, char *line);
void    texture_format_handler(t_error * error, t_texture *target, char *line);
void    rgba_handler (t_error *error, t_texture *texture, char *rgbacolor);
void    hexa_handler(t_error *error, t_texture *texture, char *hexacolor);
void    path_handler(t_error *error, t_texture *texture, char *path);


// HELPER
char    *get_next_line(int fd);
char	*concat3(char *str1, char *str2, char *sep, int tofree);
char	*find_replace(char *src, char *target, char *new, int usefree);
int     is_space(int c);
void    nullstr(char **str); // free and set to null a string 
size_t  str2dlen(char **str); // count length of arr of strings !
void    nullarr2d(void ***ptr, size_t len); // free and set to null a 2d array of size len
t_uint  rgbatoint(char *rgba); // converte rgba string to t_uint example: 255,255,255,255 to ~0
t_uint  match_count(char *str, unsigned char c); // count duplicate of char in string !
bool    contain_only(char *str, char *set); // check if string composed only of set;
char    *capitalize(const char *str); // to upper string !
t_uint  hexatoint(char *hexacolor); // converte hexa string to t_uint example: #FFFFFF to ~0 
char    **serializer(t_list *list);
t_list  *dserializer(char **arr);
char    **trim_tail_empty(char **arr);
void    transform(char *str, const char *set, int c);
void    *ft_realloc(void *ptr, size_t oldsize, size_t newsize);
char    *normalize(char *str, size_t newsize, unsigned char toapp);
void    **alloc2darr(size_t elem, size_t items, size_t itemsize);

//movements.c
void	movement_handler(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	strafe_right(t_game *game);
void	strafe_left(t_game *game);


// main

void	game_loop(void *param);
//drawing.c
void    put_pixel(mlx_image_t *img, int x, int y, int color);
void    draw_floor_ceilling(t_game *game);
int	    get_wall_color(t_textures *txt, int side, int step_x, int step_y);

//raycasting.c
void raycasting(t_game *game);
void cast_ray(t_game *game, int x);

//dda.c
void    performing_dda(t_game *game, t_ray *ray, t_dda *dda, t_wall *wall);
// double  get_perpendular(t_game *game, t_ray *ray, t_wall *wall);
double  get_perpendular(t_wall *wall, t_dda *data);
void draw_wall(t_game *game, int x, t_wall *wall, int line_height);
//void draw_wall(t_game *game, int x, t_wall *wall, t_ray *ray);
int	calculate_line_height(double perp_wall_dist);


// QUEUE
t_queue *q_create(unsigned char c, int x, int y);
void    q_delete(t_queue **node);
t_queue *q_find(t_queue *queue, int x, int y);
t_queue *q_last(t_queue *queue);
int     q_pop(t_queue **queue, t_queue *out);
void    q_push(t_queue **queue, t_queue *newq);
void    q_printQueue(t_queue *queue);
void    q_pushQueue(void);
void    q_popQueue(t_queue **queue);
void    q_empty(t_queue **queue);
bool    is_closed_bff(t_map *map, t_queue **queue); 
bool    is_nospace_bff(t_map *map, t_queue **queue);

#endif
