/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_wall_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:22:16 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/27 10:25:30 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	cub_check_wall_map(t_cub *cub, char **map)
{
	int	tab;
	int	i;

	tab = 0;
	while (map[tab])
	{
		i = 0;
		while (map[tab][i])
		{
			i++;
		}
		tab++;
	}
}
