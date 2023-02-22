/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:17:39 by tidigov           #+#    #+#             */
/*   Updated: 2022/04/16 16:12:25 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/jojo_game.h"

void	pars_map(t_jojo *map)
{
	int	y;
	int	x;

	y = -1;
	map->y = 0;
	while (map->tab[++y])
	{
		x = -1;
		map->x = 0;
		while (map->tab[y][++x])
		{
			aff_map(map, y, x);
			map->x += PXL;
		}
		map->y += PXL;
	}
}

void	aff_map(t_jojo *map, int y, int x)
{
	if (map->tab[y][x] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_wall, map->x, map->y);
	}
	else if (map->tab[y][x] == '0')
		aff_ground(map);
	else if (map->tab[y][x] == 'P')
	{
		aff_ground(map);
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_player, map->x, map->y);
	}
	else if (map->tab[y][x] == 'C')
	{
		aff_ground(map);
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_collectible, map->x, map->y);
	}
	else if (map->tab[y][x] == 'E')
	{
		aff_ground(map);
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_exit, map->x, map->y);
	}
}

void	aff_ground(t_jojo *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->is_ground, map->x, map->y);
}

void	return_error(int c, t_jojo *map)
{
	if (c == 1)
	{
		free(map->tab);
		ft_putendl_fd("player not found or too many players", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 2)
	{
		free(map->tab);
		ft_putendl_fd("Need exit and collectible !", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
