/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:00:08 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 20:24:33 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_open_map(char *map, t_game_instance *game_init)
{
	int			fd;
	int			result;

	if (!ft_map_extension(map))
		return (6);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (2);
	result = ft_read_map(fd, game_init);
	close (fd);
	return (result);
}

int	ft_read_map(int fd, t_game_instance *game_init)
{
	char	**temp_matrix;
	int		result;

	temp_matrix = ft_read_all_lines(fd);
	if (!temp_matrix)
		return (7);
	if (!temp_matrix[0])
	{
		ft_free_string_array(temp_matrix, 0);
		return (7);
	}
	game_init->map_init.matrice = temp_matrix;
	result = ft_check_read(game_init);
	return (result);
}

char	**ft_read_all_lines(int fd)
{
	char	**matrix;
	char	*line;
	int		capacity;
	int		count;

	capacity = 10;
	count = 0;
	matrix = malloc(sizeof(char *) * capacity);
	if (!matrix)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (count >= capacity - 1)
		{
			capacity *= 2;
			matrix = ft_realloc_matrix(matrix, count, capacity);
			if (!matrix)
				return (NULL);
		}
		matrix[count++] = line;
		line = get_next_line(fd);
	}
	matrix[count] = NULL;
	return (matrix);
}

char	**ft_realloc_matrix(char **old_matrix, int old_count, int new_capacity)
{
	char	**new_matrix;
	int		i;

	new_matrix = malloc(sizeof(char *) * new_capacity);
	if (!new_matrix)
	{
		ft_free_string_array(old_matrix, old_count);
		return (NULL);
	}
	i = 0;
	while (i < old_count)
	{
		new_matrix[i] = old_matrix[i];
		i++;
	}
	free(old_matrix);
	return (new_matrix);
}

int	ft_check_read(t_game_instance *game_init)
{
	int	result;

	if (!ft_map_dimensions(game_init))
		return (8);
	result = ft_is_valid_map(game_init);
	return (result);
}
