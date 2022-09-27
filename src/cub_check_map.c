/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:01:26 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/27 10:15:26 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	fs_set_radiant(t_cub *cub, char c, int y, int x)
{
	cub->player->y = y;
	cub->player->x = x;
	if (c == 'E')
		cub->player->radiant = M_PI;
	if (c == 'N')
		cub->player->radiant = M_PI_2;
	if (c == 'W')
		cub->player->radiant = 3 * M_PI;
	if (c == 'N')
		cub->player->radiant = 3 * M_PI_2;
}

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
			{
				fs_set_radiant(cub, c, tab, i);
				count++;
			}
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
	cub->player = ft_calloc(1, sizeof(t_player));
	if (!cub->player)
		cub_free_before_exit(cub, ERROR_MALLOC);
	fs_check_char_map(cub, map);
}
