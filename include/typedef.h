/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:14:02 by msidry            #+#    #+#             */
/*   Updated: 2026/01/17 12:06:39 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef unsigned int t_uint;
typedef char ** t_grid;

typedef struct s_error
{
    int stat;
    char *message;
} t_error;

typedef struct s_scene
{
    int fd;
    char *path;
    t_list *rawmap;
} t_scene;

typedef enum e_texture_type
{
    SOLID,
    IMAGE,
} t_txttype;

typedef struct s_imgtxt
{
    mlx_image_t *txt;
    char *path;
} t_imgtxt;

typedef struct s_texture
{
    t_txttype type;
    union {
        t_uint rgba;
        t_imgtxt img_texture;
    } texture;
    bool is_set;
} t_texture;

typedef struct s_textures
{
    t_texture sky_txt;
    t_texture south_txt;
    t_texture north_txt;
    t_texture east_txt;
    t_texture west_txt;
    t_texture floor_txt;
} t_textures;


typedef struct s_map
{
  t_grid  map2d;
  size_t height;
  size_t width;
} t_map;


typedef struct s_display
{
    mlx_t *mlx;
    mlx_image_t *img;
}t_display;


typedef struct  s_vector
{
    double x;
    double y;
} t_vector;

typedef t_vector t_coordinate;  

typedef struct s_player
{
    t_coordinate pos;
    t_vector dir;
    t_vector plane;
    
} t_player;

typedef struct s_ray
{
	double	camera_x;
    t_vector dir;
	size_t		map_x;
	size_t		map_y;
	double	wall_x;
}	t_ray;


typedef struct s_dda
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
}	t_dda;

typedef struct s_wall
{
	int		step_x;
	int		step_y;
	int		hit;
	int		side; // hosrizental or vertical
	double	perp_dist;
	int		line_height;
    int     tex_x;
}	t_wall;

typedef struct s_container
{
    int argc;
    char **argv;
    t_scene scene;
    t_error error;
    t_map  map;
    t_textures textures;
    t_player player;
    t_display display;

} t_game;


typedef bool(*validCallback)(t_game *game);
typedef void (*callconfi)(t_error *err, t_textures *txt, char *ln);
typedef void (*callformat)(t_error *err, t_texture *, char *frmt);

typedef struct s_queue
{
    unsigned char content;
    struct s_queue *next;
    int x;
    int y;
} t_queue;

#endif
