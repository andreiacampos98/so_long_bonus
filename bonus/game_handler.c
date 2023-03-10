/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:29:36 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/22 19:48:30 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*This function it will be call everytime that we have an event.
If the event is */
int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_exit(game);
	if (keysym == 'a' || keysym == 's' || keysym == 'w'
		|| keysym == 'd')
	{
		move_player(game, keysym);
	}
	if (game->map.follower && (keysym == 'a' || keysym == 's'
			|| keysym == 'w' || keysym == 'd'))
		move_follower(game, keysym);
	return (0);
}

/*This function it will be call everytime that we don't have an event 
and we need to close the window.*/
int	handle_btnrealease(t_game *game)
{
	destroy_images(game);
	return (0);
}
