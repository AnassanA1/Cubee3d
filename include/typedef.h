/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:14:02 by msidry            #+#    #+#             */
/*   Updated: 2026/02/22 11:22:57 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef unsigned int	t_uint;
typedef char			**t_grid;

typedef struct s_dfile
{
	char				*path;
	t_list				*rawdata;
	t_list				*config;
	t_list				*map;
	int					fd;
}						t_dfile;

typedef struct s_map
{
	t_grid				map2d;
	size_t				height;
	size_t				width;
}						t_map;

typedef struct s_display
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	char				*title;
	unsigned int		width;
	unsigned int		height;
}						t_display;

typedef struct s_vector
{
	double				x;
	double				y;
}						t_vector;

typedef t_vector		t_coordinate;

typedef struct s_player
{
	t_coordinate		pos;
	t_vector			dir;
	t_vector			plane;

}						t_player;

typedef struct s_texture_image
{
	char				*key;
	char				*value;
	mlx_image_t			*img;
}						t_texture_image;

typedef struct s_texture_solid
{
	char				*key;
	char				*value;
	t_uint				rgb;
}						t_texture_solid;

typedef struct s_container
{
	t_dfile				datafile;
	t_map				map;
	t_player			player;
	t_display			display;
	t_texture_image		txt_images[4];
	t_texture_solid		txt_solid[2];
	int					argc;
}						t_container;

typedef struct s_queue
{
	unsigned char		content;
	struct s_queue		*next;
	int					x;
	int					y;
}						t_queue;

typedef struct s_dda
{
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
}						t_dda;

typedef struct s_wall
{
	int					step_x;
	int					step_y;
	int					side;
	double				perp_dist;
	int					line_height;
	int					tex_x;
}						t_wall;

typedef struct s_ray
{
	double				camera_x;
	t_vector			dir;
	t_dda				dda;
	t_wall				wall;
	size_t				map_x;
	size_t				map_y;
	double				wall_x;
}						t_ray;

typedef struct s_line
{
	unsigned int	y_start;
	unsigned int	y_end;
	double			step;
}	t_line;

#endif
