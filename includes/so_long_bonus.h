/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:37:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/22 17:59:38 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define IMG_SIZE 32
# define A 97
# define D 100
# define S 115
# define W 119

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_mapdata
{
	char	**map;
	t_point	size;
	t_point	pp;
	t_point	np;
	t_point	fp;
	t_point	nf;
	int		player;
	int		follower;
	int		exit;
	int		collect;
	int		can_exit;
}				t_mapdata;

typedef struct s_img
{
	void			**player;
	void			**exit;
	void			*ground;
	void			*coin;
	void			*wall;
	void			*wall_ld;
	void			*wall_le;
	void			*wall_lc;
	void			*wall_lb;
	void			*wall_0_0;
	void			*wall_0_y;
	void			*wall_x_0;
	void			*wall_x_y;
	void			**enemy;
	void			*follower;
	void			*follower_r;
	void			*follower_l;
	void			*follower_u;
	void			*follower_b;
	int				size_enemy;
	int				size_player;
	int				count_enemy;
	int				count_exit;
	int				count_player;
	t_point			size;
}	t_img;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_point			window_size;
	t_mapdata		map;
	int				collect;
	int				moves;
	t_img			img;
}	t_game;

typedef enum e_components
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_components;

/*--------------Map Read-------------------*/

int			count_lines_map(char *file);
int			count_column_map(t_mapdata mapdata);
char		**allocate_memory_to_map(char *file);
char		**read_map(char *file);
t_mapdata	map(char *file);

/*--------------Checker Map-----------------*/
int			nb_exit(char **map, char *file);
int			nb_player(char **map, char *file);
int			nb_collectible(char **map, char *file);
int			valid_nb(t_mapdata mapdata);
int			valid_char(t_mapdata mapdata);
int			valid_components(t_mapdata mapdata);

int			map_surrounded_by_walls(t_mapdata mapdata);
bool		flood_fill(t_mapdata *map, t_point curr, char **maze);
bool		has_valid_path(t_mapdata *mapdata);
int			line_length_equal(t_mapdata mapdata, char *file);
int			valid_file(int argc, char *file);
int			valid_map(char *file, t_mapdata mapdata);
void		init_player(t_mapdata *mapdata);

/*--------------Game Follower-----------------*/
void		init_follower(t_mapdata *mapdata);
int			nb_follower(char **map, char *file);

/*-------------------- Game Init --------------------*/
t_game		game_init(t_mapdata *map);
int			init_window(t_game *game);
void		init_images(t_game *game);
void		init_images_player(t_game *game);
void		init_walls(t_game *game);

/*------------------- Game Images -------------------*/
void		init_enemy(t_game *game);
void		loop_images(t_game game);
void		destroy_images(t_game *game);
void		destroy_images_walls(t_game *game);
void		destroy_images_enemy(t_game *game);

/*------------------- Game Render -------------------*/
int			render(t_game *game);
void		display_counter_window(t_game *game);
void		parse_chars(t_game *game, int i, int j);
void		parse_chars_2(t_game *game, int i, int j);
void		display_walls(t_game *game, int i, int j);
void		display_walls_corners(t_game *game, int i, int j);

/*-------------------- Game Move --------------------*/
int			check_next_positions(t_game *game, char move,
				char character_next_position);
void		count_collectables_catches(t_game *game, char move);
int			win_game(t_game *game);
void		lose_game(t_game *game);
void		movement(t_game *game, char move);

/*-------------------- Game Move 2 --------------------*/
void		move_player(t_game *game, char move);
int			check_next_follower(t_game *game, char move,
				char character_next_position);
void		movement_follower(t_game *game, char move);
void		move_follower(t_game *game, char move);

/*-------------------- Game Handler --------------------*/
int			handle_btnrealease(t_game *game);
int			handle_keypress(int keysym, t_game *game);

/*-------------------- Utils --------------------*/
void		matrix_delete(char **str);
int			ft_exit(t_game *game);

#endif
