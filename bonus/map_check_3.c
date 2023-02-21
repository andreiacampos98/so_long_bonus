/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:41:40 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/21 18:50:18 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
/*In this function, I will check if there is only one player and exit. 
Furthermore, if there is ate least one collectible.*/

int	valid_components(t_mapdata mapdata)
{
	if (!valid_char(mapdata))
		return (0);
	if (!valid_nb(mapdata))
		return (0);
	if (mapdata.follower > 1)
	{
		matrix_delete(mapdata.map);
		handle_errors("You can only have one 'F'.");
		return (0);
	}
	return (1);
}

/*In this function, I will check all the requirements.*/
int	valid_map(char *file, t_mapdata mapdata)
{
	if (!valid_components(mapdata))
		return (0);
	if (!map_surrounded_by_walls(mapdata))
	{
		matrix_delete((mapdata).map);
		handle_errors("The map isn't surrounded by walls.");
		return (0);
	}
	if (!line_length_equal(mapdata, file))
	{
		matrix_delete((mapdata).map);
		handle_errors("The map isn't rectangular.");
		return (0);
	}
	if (!has_valid_path(&mapdata))
	{
		matrix_delete((mapdata).map);
		handle_errors("Invalid path!");
		return (0);
	}
	return (1);
}

void	init_player(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapdata->map[i])
	{
		while (mapdata->map[i][j])
		{
			if (mapdata->map[i][j] == PLAYER)
			{
				mapdata->pp.x = j;
				mapdata->pp.y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
