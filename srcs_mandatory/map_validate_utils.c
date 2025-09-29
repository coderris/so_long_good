/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:08:11 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 19:47:22 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_process_map_chars(t_game_instance *game_init)
{
	int		row;
	int		column;
	int		result;

	row = 0;
	while (row < game_init->map_init.rows_matrice)
	{
		column = 0;
		while (column < game_init->map_init.cols_matrice)
		{
			result = ft_count_char(game_init,
					game_init->map_init.matrice[row][column]);
			if (result != 0)
				return (result);
			column++;
		}
		row++;
	}
	return (ft_have_requires(game_init));
}

int	ft_count_char(t_game_instance *game_init, char c)
{
	if (c == PLAYER)
		game_init->game_data.count_player++;
	else if (c == EXIT)
		game_init->game_data.count_exit++;
	else if (c == COLLECTIBLE)
		game_init->game_data.count_collectible++;
	else if (c == WALL)
		game_init->game_data.count_wall++;
	else if (c == EMPTY)
		game_init->game_data.count_empty++;
	else
		return (15);
	return (0);
}
