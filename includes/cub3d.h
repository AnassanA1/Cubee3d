#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_TITLE "cub3D"

# define MOVE_SPEED 0.09
# define ROT_SPEED 0.05

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
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
	int		side;
	double	perp_dist;
	int		line_height;
}	t_wall;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	mlx_texture_t	*north_tex;
	mlx_texture_t	*south_tex;
	mlx_texture_t	*west_tex;
	mlx_texture_t	*east_tex;
}	t_textures;

typedef struct s_colors
{
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceil_r;
	int		ceil_g;
	int		ceil_b;
}	t_colors;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	player;
	t_map		map;
	t_textures	textures;
	t_colors	colors;
}	t_game;

// Initialization 
void	init_game(t_game *game);
void	init_mlx(t_game *game);
void	init_player(t_game *game);
void	set_player_direction(t_game *game, char dir);

// Parsing
//TODO: Add more parsing functions as needed

// utiles
void	error_exit(char *message);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	free_map(t_game *game);

#endif