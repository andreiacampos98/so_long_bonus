/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:58:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/14 21:55:19 by anaraujo         ###   ########.fr       */
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
	else if (game->map.map[i][j] == PLAYER)
		effect_player(game, i, j);
	else if (game->map.map[i][j] == ENEMY)
		mlx_put_image_to_window(game->mlx, game->window, game->img.enemy1,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->window, game->img.coin,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i == 0 && j == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_0_0,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i == 0 && j == (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_x_0,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i == (game->map.size.y - 1) && j == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_0_y,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i == (game->map.size.y - 1) && j == (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_x_y,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i == 0 && j != 0 && j != (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_LC,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i == (game->map.size.y - 1) && j != 0 && 
				j != (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_LB,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i != 0  && i != (game->map.size.y - 1) && j == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_LD,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && i != 0  && i != (game->map.size.y - 1) && 
				j == (game->map.size.x - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall_LE,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == WALL && (i > 0  && i < (game->map.size.y - 1)) && 
				(j < (game->map.size.x - 1) && j > 0))
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall,
			j * IMG_SIZE, i * IMG_SIZE);
}

/*mlx_loop
Loop over the given MLX pointer. 
Each hook that was registered prior to this will be called accordingly by order 
of registration.*/
/*mlx_loop_hook
Hook into the loop.*/
/*2 - KeyPress*/
/*1L<<0 - KeyPressMask*/

/*33 - ClientMessage*/
/*1L<<5 - LeaveWindowMask*/
void	loop_images(t_game game)
{
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.window, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &game);
	mlx_hook(game.window, 17, (1L << 0), ft_exit, &game);
	mlx_loop(game.mlx);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.ground);
	mlx_destroy_image(game->mlx, game->img.player1);
	mlx_destroy_image(game->mlx, game->img.player2);
	mlx_destroy_image(game->mlx, game->img.player3);
	mlx_destroy_image(game->mlx, game->img.player4);
	mlx_destroy_image(game->mlx, game->img.player5);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	destroy_images_walls(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall_0_0);
	mlx_destroy_image(game->mlx, game->img.wall_0_y);
	mlx_destroy_image(game->mlx, game->img.wall_x_0);
	mlx_destroy_image(game->mlx, game->img.wall_x_y);
	mlx_destroy_image(game->mlx, game->img.wall_LB);
	mlx_destroy_image(game->mlx, game->img.wall_LC);
	mlx_destroy_image(game->mlx, game->img.wall_LD);
	mlx_destroy_image(game->mlx, game->img.wall_LE);
}

void	destroy_images_enemy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.enemy1);
	mlx_destroy_image(game->mlx, game->img.enemy2);
	mlx_destroy_image(game->mlx, game->img.enemy3);
	mlx_destroy_image(game->mlx, game->img.enemy4);
	mlx_destroy_image(game->mlx, game->img.enemy5);
	mlx_destroy_image(game->mlx, game->img.enemy6);
	mlx_destroy_image(game->mlx, game->img.enemy7);
	mlx_destroy_image(game->mlx, game->img.enemy8);
}