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

# define MOVE_SPEED 0.04
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
	double	camera_x; // 
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
	int		side; // hosrizental or vertical
	double	perp_dist;
	int		line_height;
}	t_wall;

typedef struct s_map
{
	char	**grid; //fill grid with all map lines
	int		width; // width to the longest line length
	int		height; // height to the number of map lines
}	t_map;

typedef struct s_textures
{
	char			*north; // store path in north
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
char	*trim_newline(char *str);
int	parse_texture_line(char *line, t_game *game);
char	*skip_spaces(char *line);
int	parse_color(char *line, t_colors *colors, int is_ceiling);
int	parse_textures(int fd, t_game *game);
int	all_textures_loaded(t_game *game);
int	open_file(char *filename);
int	parse_file(char *filename, t_game *game);
int	get_line_width(char *line);
char	**store_map_lines(int fd, int *height, int *width);
char	**allocate_map_grid(int height, int width);
void	fill_map_line(char *dest, char *src, int width);
int	parse_map(int fd, t_game *game);
int	is_valid_char(char c);
int	check_surrounding(t_game *game, int x, int y);
int	check_borders(t_game *game);
int	find_player(t_game *game);
int	is_valid_map(t_game *game);

//drawing.c
void    put_pixel(mlx_image_t *img, int x, int y, int color);
void    draw_floor_ceilling(t_game *game);
int	get_wall_color(int side, int step_x, int step_y);

//raycasting.c
void raycasting(t_game *game);
void cast_ray(t_game *game, int x);

//dda.c
void    performing_dda(t_game *game, t_ray *ray, t_dda *dda, t_wall *wall);
// double  get_perpendular(t_game *game, t_ray *ray, t_wall *wall);
double  get_perpendular(t_wall *wall, t_dda *data);
void	draw_wall(t_game *game, int x, t_wall *wall, int line_height);
int	calculate_line_height(double perp_wall_dist);


// utiles
void	error_exit(char *message);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	free_map(t_game *game);

//keys.c
void	key_hook(mlx_key_data_t keydata, void *param);

//movements.c
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	strafe_right(t_game *game);
void	strafe_left(t_game *game);

#endif