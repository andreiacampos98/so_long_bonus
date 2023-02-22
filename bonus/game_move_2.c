/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:40:26 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/22 19:44:31 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_player(t_game *game, char move)
{
	static t_components	previous = EMPTY;

	if (check_next_positions(game, move, WALL) == 1)
		return ;
	game->map.map[game->map.pp.y][game->map.pp.x] = previous;
	game->moves++;
	if (game->collect == game->map.collect)
	{
		game->map.can_exit = 1;
		game->img.count_exit = 1;
	}
	count_collectables_catches(game, move);
	movement(game, move);
	if (check_next_positions(game, move, ENEMY) == 1
		|| check_next_positions(game, move, FOLLOWER) == 1)
		lose_game(game);
	if (check_next_positions(game, move, COLLECTABLE) == 0)
		previous = game->map.map[game->map.np.y][game->map.np.x];
	else
		previous = EMPTY;
	if (game->map.can_exit == 1
		&& game->map.map[game->map.np.y][game->map.np.x] == EXIT)
		win_game(game);
	game->map.map[game->map.np.y][game->map.np.x] = PLAYER;
	game->map.pp = game->map.np;
}

int	check_next_follower(t_game *game, char move, char character_next_position)
{
	int	y;
	int	x;

	y = game->map.fp.y;
	x = game->map.fp.x;
	if ((move == 'w' && game->map.map[y - 1][x] == character_next_position)
		|| (move == 's' && game->map.map[y + 1][x] == character_next_position)
		|| (move == 'a' && game->map.map[y][x - 1] == character_next_position)
		|| (move == 'd' && game->map.map[y][x + 1] == character_next_position))
		return (1);
	return (0);
}

void	movement_follower(t_game *game, char move)
{
	if (move == 'd')
	{
		game->map.nf = (t_point){game->map.fp.x + 1, game->map.fp.y};
		game->img.follower = game->img.follower_r;
	}
	else if (move == 'a')
	{
		game->map.nf = (t_point){game->map.fp.x - 1, game->map.fp.y};
		game->img.follower = game->img.follower_l;
	}
	else if (move == 's')
	{
		game->map.nf = (t_point){game->map.fp.x, game->map.fp.y + 1};
		game->img.follower = game->img.follower_b;
	}
	else if (move == 'w')
	{
		game->map.nf = (t_point){game->map.fp.x, game->map.fp.y - 1};
		game->img.follower = game->img.follower_u;
	}
}

void	move_follower(t_game *game, char move)
{
	static t_components	previous = EMPTY;

	if (check_next_follower(game, move, WALL) == 1)
		return ;
	if (check_next_follower(game, move, PLAYER) == 1)
		lose_game(game);
	game->map.map[game->map.fp.y][game->map.fp.x] = previous;
	movement_follower(game, move);
	previous = game->map.map[game->map.nf.y][game->map.nf.x];
	game->map.map[game->map.nf.y][game->map.nf.x] = FOLLOWER;
	game->map.fp = game->map.nf;
}
