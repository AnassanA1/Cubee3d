/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:13:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/17 15:33:52 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// STD HEADERS
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>

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
void		input_validator(t_game *ref);
void		mostBeGood(t_game **ref);
bool		isAllOk(t_game *ref);

// MAP && scene
void		map_handler(t_game *ref);
void		read_raw_map(t_game *ref);
int		isMapConfig(char *line);

// TEXTURES 
void	texture_handler(t_game *ref);
int     config_handler(t_error *error, t_gametxt *textures, char *line);
void	set_south_texture(t_error *err, t_gametxt *textures, char *line);
void	set_north_texture(t_error *err, t_gametxt *textures, char *line);
void	set_east_texture(t_error *err, t_gametxt *textures, char *line);
void	set_west_texture(t_error *err, t_gametxt *textures, char *line);
void	set_sky_texture(t_error *err, t_gametxt *textures, char *line);
void	set_floor_texture(t_error *err, t_gametxt *textures, char *line);
void    texture_format_handler(t_error * error, t_texture *target, char *line);


// HELPER
char	*concat3(char *str1, char *str2, char *sep, int tofree);
char	*find_replace(char *src, char *target, char *new, int usefree);
int     is_space(int c);
void    nullstr(char **str); // free and set to null a string 
size_t  str2dlen(char **str); // count length of arr of strings !
void    nullarr2d(void ***ptr, size_t len); // free and set to null a 2d array of size len
t_uint  rgbatoint(char *rgba); // converte rgba string to t_uint example: 255,255,255,255 to ~0
t_uint  match_count(char *str, unsigned char c); // count duplicate of char in string !
bool    contain_only(char *str, char *set); // check if string composed only of set;

#endif
