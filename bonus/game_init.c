/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:52:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/14 21:49:02 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*This function initiate the struct game.*/
t_game	game_init(t_mapdata *map)
{
	t_game	game;

	game.moves = 0;
	game.collect = 0;
	game.map = (*map);
	game.window_size.x = map->size.x * IMG_SIZE;
	game.window_size.y = map->size.y * IMG_SIZE;
	return (game);
}

/*Initializes the MLX library. Must be called before ANY other function. 
Will return NULL if initialization failed.*/
/*Creates a new window instance. It will return a window instance pointer. 
This should be saved for future reference.*/
int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->window = mlx_new_window(game->mlx, game->window_size.x,
			game->window_size.y, "so_long");
	if (game->window == NULL)
	{
		free(game->window);
		return (0);
	}
	return (1);
}

/*This function initiate the images.*/
void	init_images(t_game *game)
{
	game->img.size.x = IMG_SIZE;
	game->img.size.y = IMG_SIZE;
	game->img.player1 = mlx_xpm_file_to_image(game->mlx, "imgs/14.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player2 = mlx_xpm_file_to_image(game->mlx, "imgs/15.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player3 = mlx_xpm_file_to_image(game->mlx, "imgs/16.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player4 = mlx_xpm_file_to_image(game->mlx, "imgs/17.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player5 = mlx_xpm_file_to_image(game->mlx, "imgs/18.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "imgs/19.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.ground = mlx_xpm_file_to_image(game->mlx, "imgs/10.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "imgs/12.xpm",
			&(game->img.size.x), &(game->img.size.y));
}

void	init_walls(t_game *game)
{
	game->img.wall_0_0 = mlx_xpm_file_to_image(game->mlx, "imgs/1.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_0_y = mlx_xpm_file_to_image(game->mlx, "imgs/4.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_x_0 = mlx_xpm_file_to_image(game->mlx, "imgs/3.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_x_y = mlx_xpm_file_to_image(game->mlx, "imgs/6.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_LE = mlx_xpm_file_to_image(game->mlx, "imgs/9.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_LD = mlx_xpm_file_to_image(game->mlx, "imgs/7.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_LC = mlx_xpm_file_to_image(game->mlx, "imgs/2.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_LB = mlx_xpm_file_to_image(game->mlx, "imgs/5.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "imgs/8.xpm",
			&(game->img.size.x), &(game->img.size.y));
}

void	init_enemy(t_game *game)
{
	game->img.enemy1 = mlx_xpm_file_to_image(game->mlx, "imgs/31.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy2 = mlx_xpm_file_to_image(game->mlx, "imgs/32.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy3 = mlx_xpm_file_to_image(game->mlx, "imgs/33.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy4= mlx_xpm_file_to_image(game->mlx, "imgs/34.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy5 = mlx_xpm_file_to_image(game->mlx, "imgs/35.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy6 = mlx_xpm_file_to_image(game->mlx, "imgs/36.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy7 = mlx_xpm_file_to_image(game->mlx, "imgs/37.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy8 = mlx_xpm_file_to_image(game->mlx, "imgs/38.xpm",
			&(game->img.size.x), &(game->img.size.y));
}
