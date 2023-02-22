/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:54:26 by tidigov           #+#    #+#             */
/*   Updated: 2022/04/14 14:55:22 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/jojo_game.h"

int	check_move(t_jojo *map, int x, int y)
{
	if (map->tab[x][y] == '0' || map->tab[x][y] == 'P')
		return (1);
	else if (map->tab[x][y] == 'E')
		return (2);
	else if (map->tab[x][y] == 'C')
		return (3);
	return (0);
}

void	move_and_collect(t_jojo *map)
{
	write(STDOUT_FILENO, "move :", 6);
	ft_putnbr_fd(map->move, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "collectible :", 13);
	ft_putnbr_fd(map->nbr_collect, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}

int	key_assign(int key, t_jojo *map)
{
	if (key == ESC)
		exit(0);
	if (key == W_KEY)
		player_up(map);
	if (key == A_KEY)
		player_left(map);
	if (key == S_KEY)
		player_down(map);
	if (key == D_KEY)
		player_right(map);
	return (0);
}
