/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:00:22 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 19:47:37 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_counters(t_game_instance *game_init)
{
	game_init->game_data.count_player = 0;
	game_init->game_data.count_exit = 0;
	game_init->game_data.count_collectible = 0;
	game_init->game_data.count_wall = 0;
	game_init->game_data.count_empty = 0;
}

int	ft_get_row_length(t_game_instance *game_init, int row)
{
	int	j;
	int	row_len;

	row_len = 0;
	j = 0;
	while (game_init->map_init.matrice[row][j]
		&& game_init->map_init.matrice[row][j] != '\n')
	{
		row_len++;
		j++;
	}
	return (row_len);
}

int	ft_count_map_objects(t_game_instance *game_init)
{
	if (!game_init || !game_init->map_init.matrice)
		return (7);
	ft_init_counters(game_init);
	return (ft_process_map_chars(game_init));
}

char	**copy_map(char **src, int rows)
{
	char	**dst;
	int		i;

	dst = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dst[i] = ft_copy_row(src[i]);
		if (!dst[i])
		{
			ft_free_partial_copy(dst, i);
			return (NULL);
		}
		i++;
	}
	dst[rows] = NULL;
	return (dst);
}
