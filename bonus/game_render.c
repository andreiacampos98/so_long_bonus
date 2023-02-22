/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:14:16 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/22 17:39:59 by anaraujo         ###   ########.fr       */
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
