/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/28 08:50:59 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int cub_game_loop(t_cub *cub)
{
	if (cub->world->update)
	{
		cub_draw_world(cub);
		ft_printf("update and display x:%d y:%d\n", cub->player->x, cub->player->y);
		cub->world->update = false;
	}
	return (0);
}