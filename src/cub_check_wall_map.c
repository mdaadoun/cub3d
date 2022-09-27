/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_wall_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:22:16 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/27 14:05:39 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static bool	fs_check_cub(char **map, int y, int x)
{
	char	*line;

	line = map[y - 1];
	if (line[x - 1] == ' ' || line[x] == ' ' || line[x + 1] == ' ')
		return (true);
	line = map[y];
	if (line[x - 1] == ' ' || line[x + 1] == ' ')
		return (true);
	line = map[y + 1];
	if (line[x - 1] == ' ' || line[x] == ' ' || line[x + 1] == ' ')
		return (true);
	return (false);
}

void	cub_check_wall_map(t_cub *cub, char **map)
{
	int		tab;
	int		i;
	char	c;

	tab = 0;
	while (map[tab])
	{
		i = 0;
		while (map[tab][i])
		{
			c = map[tab][i];
			if (c == '0' || c == 'N' || c == 'S'
				|| c == 'E' || c == 'W')
				if (fs_check_cub(map, tab, i))
					cub_free_before_exit(cub, ERROR_MAP);
			i++;
		}
		tab++;
	}
}
