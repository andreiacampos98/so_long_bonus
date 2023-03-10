/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:52:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/21 14:21:41 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*This function initiate the struct game.*/
t_game	game_init(t_mapdata *map)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
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
	game->img.exit = malloc(2 * sizeof(void *));
	game->img.exit[0] = mlx_xpm_file_to_image(game->mlx, "imgs/19.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.exit[1] = mlx_xpm_file_to_image(game->mlx, "imgs/20.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.ground = mlx_xpm_file_to_image(game->mlx, "imgs/10.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "imgs/12.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.follower = mlx_xpm_file_to_image(game->mlx, "imgs/40.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.follower_r = mlx_xpm_file_to_image(game->mlx, "imgs/43.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.follower_l = mlx_xpm_file_to_image(game->mlx, "imgs/55.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.follower_u = mlx_xpm_file_to_image(game->mlx, "imgs/47.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.follower_b = mlx_xpm_file_to_image(game->mlx, "imgs/51.xpm",
			&(game->img.size.x), &(game->img.size.y));
}

void	init_images_player(t_game *game)
{
	game->img.player = malloc(5 * sizeof(void *));
	game->img.size_player = 5;
	game->img.player[0] = mlx_xpm_file_to_image(game->mlx, "imgs/14.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player[1] = mlx_xpm_file_to_image(game->mlx, "imgs/15.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player[2] = mlx_xpm_file_to_image(game->mlx, "imgs/16.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player[3] = mlx_xpm_file_to_image(game->mlx, "imgs/17.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.player[4] = mlx_xpm_file_to_image(game->mlx, "imgs/18.xpm",
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
	game->img.wall_le = mlx_xpm_file_to_image(game->mlx, "imgs/9.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_ld = mlx_xpm_file_to_image(game->mlx, "imgs/7.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_lc = mlx_xpm_file_to_image(game->mlx, "imgs/2.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall_lb = mlx_xpm_file_to_image(game->mlx, "imgs/5.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "imgs/8.xpm",
			&(game->img.size.x), &(game->img.size.y));
}
