/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:00:16 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 20:37:17 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_is_valid_map(t_game_instance *game_init)
{
	int	result;

	result = ft_is_map_shape_valid(game_init);
	if (result != 0)
		return (result);
	result = ft_count_map_objects(game_init);
	if (result != 0)
		return (result);
	result = ft_is_wall(game_init);
	if (result != 0)
		return (result);
	result = ft_is_map_resoluble(game_init);
	if (result != 0)
		return (result);
	return (0);
}

int	ft_is_map_shape_valid(t_game_instance *game_init)
{
	int	ref_len;

	if (!game_init || !game_init->map_init.matrice)
		return (8);
	if (game_init->map_init.rows_matrice <= 0)
		return (8);
	ref_len = ft_get_row_length(game_init, 0);
	if (ref_len <= 0)
		return (8);
	return (ft_check_all_rows_length(game_init, ref_len));
}

int	ft_check_all_rows_length(t_game_instance *game_init, int ref_len)
{
	int	i;
	int	current_len;

	i = 0;
	while (i < game_init->map_init.rows_matrice)
	{
		current_len = ft_get_row_length(game_init, i);
		if (current_len != ref_len)
			return (8);
		i++;
	}
	game_init->map_init.cols_matrice = ref_len;
	return (0);
}

int	ft_is_wall(t_game_instance *game_init)
{
	int		i;
	int		j;

	i = 0;
	while (i < game_init->map_init.rows_matrice)
	{
		j = 0;
		while (j < game_init->map_init.cols_matrice)
		{
			if (i == 0 || j == 0 || i == game_init->map_init.rows_matrice - 1
				|| j == game_init->map_init.cols_matrice - 1)
			{
				if (game_init->map_init.matrice[i][j] != WALL)
					return (14);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_have_requires(t_game_instance *game_init)
{
	if (game_init->game_data.count_player == 0)
		return (9);
	if (game_init->game_data.count_player > 1)
		return (12);
	if (game_init->game_data.count_exit == 0)
		return (10);
	if (game_init->game_data.count_exit > 1)
		return (13);
	if (game_init->game_data.count_collectible < 1)
		return (11);
	return (0);
}
