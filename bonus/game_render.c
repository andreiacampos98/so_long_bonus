/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:14:16 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/21 19:27:32 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*In this funcion, I will take the game. 
Then I will do a loop, where while exist mapdata, I will call the function
parse_char, in order to build my map with the images.
I also call the function display_counter_window in order to display the 
number of moves that the player do.*/
int	render(t_game *game)
{
	int		i;
	int		j;

	if (game->window == NULL)
		return (0);
	i = 0;
	j = 0;
	while (game->map.map[i])
	{
		while (game->map.map[i][j] && game->map.map[i][j] != '\n')
		{
			parse_chars(game, i, j);
			parse_chars_2(game, i, j);
			j++;
			display_counter_window(game);
		}
		j = 0;
		i++;
	}
	return (1);
}

void	display_counter_window(t_game *game)
{
	char	*nb_moves;

	nb_moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 20, 15, 206, "Moves: ");
	mlx_string_put(game->mlx, game->window, 70, 15, 206, nb_moves);
	if (nb_moves)
		free(nb_moves);
}

/*This function takes the mapdata and put the image in the window*/
void	parse_chars(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == EMPTY)
		mlx_put_image_to_window(game->mlx, game->window, game->img.ground,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == FOLLOWER)
		mlx_put_image_to_window(game->mlx, game->window, game->img.follower,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.exit[game->img.count_exit], j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->window, game->img.coin,
			j * IMG_SIZE, i * IMG_SIZE);
}

void	parse_chars_2(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == PLAYER)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.player[game->img.count_player++ % game->img.size_player],
			j * IMG_SIZE, i * IMG_SIZE);
		usleep(20000);
	}
	else if (game->map.map[i][j] == ENEMY)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.enemy[game->img.count_enemy++ % game->img.size_enemy],
			j * IMG_SIZE, i * IMG_SIZE);
		usleep(20000);
	}
	else if (game->map.map[i][j] == WALL)
	{
		display_walls(game, i, j);
		display_walls_corners(game, i, j);
	}
}

void	display_walls_corners(t_game *game, int i, int j)
{
	if (i == 0 && j == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_0_0,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (i == 0 && j == (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_x_0,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (i == (game->map.size.y - 1) && j == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_0_y,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (i == (game->map.size.y - 1) && j == (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_x_y,
			j * IMG_SIZE, i * IMG_SIZE);
}

void	display_walls(t_game *game, int i, int j)
{
	if (i == 0 && j != 0 && j != (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_lc,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (i == (game->map.size.y - 1) && j != 0
		&& j != (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_lb,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (i != 0 && i != (game->map.size.y - 1) && j == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_ld,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (i != 0 && i != (game->map.size.y - 1)
		&& j == (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_le,
			j * IMG_SIZE, i * IMG_SIZE);
	else if ((i > 0 && i < (game->map.size.y - 1))
		&& (j < (game->map.size.x - 1) && j > 0))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall,
			j * IMG_SIZE, i * IMG_SIZE);
}
