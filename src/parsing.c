/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:47:39 by tidigov           #+#    #+#             */
/*   Updated: 2022/04/16 16:09:20 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/jojo_game.h"

void	co_ex(t_jojo *map)
{
	int	a;
	int	b;

	a = 0;
	map->nbr_exit = 0;
	map->nbr_collect = 0;
	while (map->tab[a])
	{
		b = 0;
		while (map->tab[a][b])
		{
			if (map->tab[a][b] == 'C')
				map->nbr_collect++;
			else if (map->tab[a][b] == 'E')
				map->nbr_exit++;
			b++;
		}
		a++;
	}
	if (map->nbr_exit <= 0 || map->nbr_collect <= 0)
		return_error(2, map);
}

void	position_player(t_jojo *map)
{
	int	i;
	int	a;

	i = 0;
	map->nbr_x = 0;
	map->nbr_y = 0;
	map->nbr_player = 0;
	while (map->tab[i])
	{
		a = 0;
		while (map->tab[i][a])
		{
			if (map->tab[i][a] == 'P')
			{
				map->nbr_x += a;
				map->nbr_y += i;
				map->nbr_player++;
			}
			a++;
		}
		i++;
	}
	if (map->nbr_player <= 0 || map->nbr_player > 1)
		return_error(1, map);
}
