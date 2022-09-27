/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:01:26 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/27 09:42:48 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	fs_check_char_map(t_cub *cub, char **map)
{
	int		count;
	int		i;
	int		tab;
	char	c;

	tab = 0;
	count = 0;
	while (map[tab])
	{
		i = 0;
		while (map[tab][i])
		{
			c = map[tab][i];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				count++;
			i++;
		}
		tab++;
	}
	if (count != 1)
		cub_free_before_exit(cub, ERROR_MAP);
}

void	cub_check_map(t_cub *cub)
{
	char	**map;

	map = cub->map;
	fs_check_char_map(cub, map);
}
