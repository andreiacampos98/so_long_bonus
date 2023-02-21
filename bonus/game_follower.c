/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_follower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:47:32 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/21 18:32:32 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	nb_flower(char **map, char *file)
{
	int	i;
	int	j;
	int	line_count;
	int	count_collectible;

	count_collectible = 0;
	line_count = count_lines_map(file);
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'F')
				count_collectible++;
			j++;
		}
		i++;
	}
	return (count_collectible);
}

void	init_follower(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapdata->map[i])
	{
		while (mapdata->map[i][j])
		{
			if (mapdata->map[i][j] == FOLLOWER)
			{
				mapdata->fp.x = j;
				mapdata->fp.y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
