/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:58:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/21 14:23:04 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_enemy(t_game *game)
{
	game->img.enemy = malloc(8 * sizeof(void *));
	game->img.size_enemy = 8;
	game->img.enemy[0] = mlx_xpm_file_to_image(game->mlx, "imgs/31.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy[1] = mlx_xpm_file_to_image(game->mlx, "imgs/32.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy[2] = mlx_xpm_file_to_image(game->mlx, "imgs/33.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy[3] = mlx_xpm_file_to_image(game->mlx, "imgs/34.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy[4] = mlx_xpm_file_to_image(game->mlx, "imgs/35.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy[5] = mlx_xpm_file_to_image(game->mlx, "imgs/36.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy[6] = mlx_xpm_file_to_image(game->mlx, "imgs/37.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.enemy[7] = mlx_xpm_file_to_image(game->mlx, "imgs/38.xpm",
			&(game->img.size.x), &(game->img.size.y));
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
/*1L<<5 - leaveWindowMask*/
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
	mlx_destroy_image(game->mlx, game->img.player[0]);
	mlx_destroy_image(game->mlx, game->img.player[1]);
	mlx_destroy_image(game->mlx, game->img.player[2]);
	mlx_destroy_image(game->mlx, game->img.player[3]);
	mlx_destroy_image(game->mlx, game->img.player[4]);
	mlx_destroy_image(game->mlx, game->img.exit[0]);
	mlx_destroy_image(game->mlx, game->img.exit[1]);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_image(game->mlx, game->img.follower);
	mlx_destroy_image(game->mlx, game->img.follower_l);
	mlx_destroy_image(game->mlx, game->img.follower_r);
	mlx_destroy_image(game->mlx, game->img.follower_u);
	mlx_destroy_image(game->mlx, game->img.follower_b);
	mlx_destroy_display(game->mlx);
	free(game->img.exit);
	free(game->img.player);
	free(game->mlx);
}

void	destroy_images_walls(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall_0_0);
	mlx_destroy_image(game->mlx, game->img.wall_0_y);
	mlx_destroy_image(game->mlx, game->img.wall_x_0);
	mlx_destroy_image(game->mlx, game->img.wall_x_y);
	mlx_destroy_image(game->mlx, game->img.wall_lb);
	mlx_destroy_image(game->mlx, game->img.wall_lc);
	mlx_destroy_image(game->mlx, game->img.wall_ld);
	mlx_destroy_image(game->mlx, game->img.wall_le);
	mlx_destroy_image(game->mlx, game->img.wall);
}

void	destroy_images_enemy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.enemy[0]);
	mlx_destroy_image(game->mlx, game->img.enemy[1]);
	mlx_destroy_image(game->mlx, game->img.enemy[2]);
	mlx_destroy_image(game->mlx, game->img.enemy[3]);
	mlx_destroy_image(game->mlx, game->img.enemy[4]);
	mlx_destroy_image(game->mlx, game->img.enemy[5]);
	mlx_destroy_image(game->mlx, game->img.enemy[6]);
	mlx_destroy_image(game->mlx, game->img.enemy[7]);
	free(game->img.enemy);
}
