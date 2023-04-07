/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:04:04 by sheali            #+#    #+#             */
/*   Updated: 2023/04/06 21:33:42 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <memory.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h> 
# include "../libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH 720
# define HEIGHT 720
# define IMG_W 64
# define IMG_H 64
# define SQUARES 32
# define TRUE 1
# define FALSE 0

# define A "Usage: ./so_long <name>.ber\n"
# define B "Missing map components.\n"
# define C "Map is leaking.\n"
# define D "Map has no valid path.\n"
# define E "Empty map..\n"
# define F "Wrong map format: use .ber\n"
# define G "Map structure is incorrect.\n"
# define H "Warning: map error!\n"
# define I "Map has forbidden element!\n"

typedef enum e_errors
{
	USAGE		= 1,
	MISSEN_COMP = 2,
	MAP_LEAK	= 3,
	MAP_PATH	= 4,
	EMPTY_MAP	= 5,
	MAP_FORMAT	= 6,
	MAP_STRUCT	= 7,
	MAP_ERR		= 8,
	FRBDN_CHAR	= 9
}				t_errors;

typedef struct s_position
{
	int		x;
	int		y;
}			t_position;

typedef struct s_move
{
	mlx_texture_t	*left[5];	
	mlx_texture_t	*right[5];	
	mlx_image_t		*still_right[5];
	mlx_image_t		*still_left[5];
	mlx_texture_t	*up[5];	
	mlx_texture_t	*down[5];	
	mlx_image_t		*still_down[5];
	mlx_image_t		*still_up[5];
	mlx_image_t		*stand_still;
}					t_move;

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*enemy[3];
	mlx_texture_t	*exit[2];
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*enemy_img[3];
	mlx_image_t		*exit_img[2];

}					t_texture;

typedef struct s_map
{
	char				**map;
	t_position			*player;
	t_position			*moves[5];
	t_position			*exit;
	t_list				*lst_v;
	t_list				*lst_vv;
	int					map_loop;
	char				moved_p;
	int					player_count;
	int					collectible_count;
	int					exit_count;
}				t_map;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_image_t		*score;
	mlx_image_t		*image_p;
	mlx_image_t		*container_p;
	t_list			*lst_e;
	t_list			*lst_c;
	t_move			*stand_still;
	t_texture		*squares;
	mlx_texture_t	*icon;
	t_position		*moves_p[5];
	int				_h;
	int				_w;
	char			**maps;
	char			*map;
	char			*move_trigger;
	mlx_image_t		*texture;
	mlx_texture_t	*player;
	char			*count_c;
	int				width;
	int				height;
}					t_data;

int			error_prints(int num);
int			element_is_forbidden(char *map);
int			print_sys_error(char errnum);
int			map_has_errors(char *argv);
t_position	get_new_position(t_position *player, t_position *movement);
void		add_collectable_to_list(t_data **data, int x, int y);
void		put_enemy(t_data **data, int width, int height);
void		draw_floor(t_data **data, char c, int width, int height);
void		add_player_to_game(t_data **data);
void		add_exit(t_data **data);
void		add_player_container(t_data **data);
void		draw_enemies(t_data **data);
void		draw_collectables(t_data **data);
void		draw_squares(t_data **data);
void		buildmap(t_data **data);
int			count_collectible(char *map);
void		remove_collectible_list(t_data **data);
void		collected_by_player(t_data **data);
void		all_collectibles_collected(t_data *data);
int			not_visited(t_position *position, t_list *visited_list);
int			position_is_valid(t_position position, t_map **map);
t_position	get_new_position(t_position *player, t_position *movement);
void		init_game_data(t_data **data, char *argv);
void		function_move(t_data *data, t_position *position);
void		keyhook(mlx_key_data_t keydata, void *param);
void		hook(void *param);
void		start_game(char *argv);
void		player_is_on_enemy(t_data **data);
int			player_is_on_exit(t_data **data);
void		animate_idle_player(void *param);
int			movement_is_valid(t_data *data, t_position *position);
void		initialize_movements(t_data **data);
void		move_player(t_position new_pos, t_map **map);
void		step_back(t_map **map);
void		check_map_path(t_map *map);
int			has_no_valid_path(t_map *map);
int			get_map_bytes(char *map);
char		*read_map_file(char *filename);
void		load_idle_images(t_data **data);
void		load_tile_images(t_data **data);
void		init_tile_textures(t_data **data);
void		init_move_texture(t_data **data);
void		delete_tile_textures(t_data **data);
void		delete_idle_textures(t_data **data);
void		destroy_movements(t_data **data);
void		destroy_idle_structure(t_data **data);
void		destroy_tile_structure(t_data **data);
t_position	*get_exit_position(char **map);
t_position	*get_player_position(char **map);
void		destroy_structure(t_map *map);
t_map		*init_structure(char *map_string);
void		free_n_remove_img_node(t_data **data,
				mlx_image_t *image, t_list *head);
t_position	*get_exit_position(char **map);
t_position	*get_player_position(char **map);
void		destroy_structure(t_map *map);
t_map		*init_structure(char *map_string);
t_position	*get_component(char **map, char type);
void		free_string_array(char **split);
void		free_game_data(t_data **data);
void		remove_collectible_list(t_data **data);
void		delete_collectible_node(t_data **data, t_list *node);
int			count_line(char **xy_map);
int			get_map_size(char *map);
char		*print_map(char *map);
int			forbidden_char(char c);
int			count_element(char *map, char c);
int			check_element(char *map);
int			check_shape(char *map);
int			check_border(char *map);
int			check_border_lr(char *map);
int			check_border_tb(char *map);
int			invalid_file_path(char *argv);
char		**print_twodimention_map(char *map);

#endif
