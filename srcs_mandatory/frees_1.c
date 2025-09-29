/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:39:00 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 14:41:43 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_partial_copy(char **dst, int up_to)
{
	while (--up_to >= 0)
		free(dst[up_to]);
	free(dst);
}

void	free_map_copy(char **mat, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
