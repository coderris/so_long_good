/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:59:10 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 20:47:40 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_get_error_message_plus(int error_code)
{
	if (error_code == 11)
		return ("Error\nNo enough collectibles\n");
	else if (error_code == 12)
		return ("Error\nDuplicate player\n");
	else if (error_code == 13)
		return ("Error\nDuplicate exit\n");
	else if (error_code == 14)
		return ("Error\nNot surrounded by walls\n");
	else if (error_code == 15)
		return ("Error\nWrong characters\n");
	else if (error_code == 16)
		return ("Error\nNo valid path\n");
	else if (error_code == 17)
		return ("Error\nTry create one valid map!\n");
	else
		return ("Error\nUnknown error\n");
}

static char	*ft_get_error_message(int error_code)
{
	if (error_code == 1)
		return ("Error\nPermission denied\n");
	else if (error_code == 2)
		return ("Error\nNo exist map\n");
	else if (error_code == 3)
		return ("Error\nCheck library compatibility!\n");
	else if (error_code == 4)
		return ("Error\nWrong number of arguments\n");
	else if (error_code == 5)
		return ("Error\nThis is a directory.\n");
	else if (error_code == 6)
		return ("Error\nBad extension\n");
	else if (error_code == 7)
		return ("Error\nMemory allocation failed (malloc).\n");
	else if (error_code == 8)
		return ("Error\nNo rectangular\n");
	else if (error_code == 9)
		return ("Error\nNo player\n");
	else if (error_code == 10)
		return ("Error\nNo exit\n");
	else
		return (ft_get_error_message_plus(error_code));
}

void	ft_handle_error(int error_code, t_game_instance *game_init)
{
	if (game_init)
		ft_free_map(game_init);
	ft_printf("%s", ft_get_error_message(error_code));
	exit(error_code);
}
