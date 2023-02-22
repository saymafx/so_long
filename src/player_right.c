/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:25:33 by tidigov           #+#    #+#             */
/*   Updated: 2022/04/14 14:26:34 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/jojo_game.h"

static void	check_move_right(t_jojo *map)
{
	if (check_move(map, map->nbr_y, map->nbr_x) == 3)
	{
		map->nbr_collect--;
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y][map->nbr_x - 1] = '0';
	}
	else if (check_move(map, map->nbr_y, map->nbr_x) == 2 && !map->nbr_collect)
	{
		free_tab(map);
		exit(EXIT_SUCCESS);
	}
	if (map->tab[map->nbr_y][map->nbr_x - 1] != 'E' &&
		map->tab[map->nbr_y][map->nbr_x] != 'E')
	{
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y][map->nbr_x - 1] = '0';
	}
	map->is_player = mlx_xpm_file_to_image(map->mlx, map->player_right,
			&map->screen_width, &map->screen_height);
}

void	player_right(t_jojo *map)
{
	map->nbr_x++;
	if (check_move(map, map->nbr_y, map->nbr_x) == 2
		&& map->nbr_collect)
		map->nbr_x--;
	else if (check_move(map, map->nbr_y, map->nbr_x) == 0)
		map->nbr_x--;
	else if (check_move(map, map->nbr_y, map->nbr_x))
	{
		check_move_right(map);
		pars_map(map);
		map->move++;
		move_and_collect(map);
	}
}
