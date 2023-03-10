/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/21 18:42:03 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*In the main, I will call the funtion I will call the funtion valid map 
in order to check if the map is valid. 
Then, I will call the funtion game_start_map in order to fill the struct game.
To initiate a loop, we call the mlx_loop function with the mlx instance as only 
parameter.Now for each frame it requires, it will call the function update with 
the parameter YourStruct. */
int	main(int argc, char **argv)
{
	t_game		game;
	t_mapdata	mapdata;

	if (!valid_file(argc, argv[1]))
		return (0);
	mapdata = map(argv[1]);
	if (!valid_map(argv[1], mapdata))
		return (0);
	game = game_init(&mapdata);
	if (!init_window(&game))
		return (0);
	init_images(&game);
	init_walls(&game);
	init_enemy(&game);
	init_images_player(&game);
	render(&game);
	loop_images(game);
	destroy_images_enemy(&game);
	destroy_images_walls(&game);
	destroy_images(&game);
	if (game.map.map)
		matrix_delete(game.map.map);
	return (0);
}
