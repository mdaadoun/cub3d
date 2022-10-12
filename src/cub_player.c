/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:54 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/12 16:26:56 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	fs_move_player_left(t_cub *cub)
{
	t_f32	x;
	t_f32	y;

	x = cub->player->grid_x;
	y = cub->player->grid_y;
	x += sin(cub->player->angle + (M_PI / 2)) * SPEED;
	y += (cos(cub->player->angle + (M_PI / 2)) * -1) * SPEED;
	if (cub_player_can_go(cub, x, y))
	{
		cub->player->grid_x = x;
		cub->player->grid_y = y;
	}
}

static void	fs_move_player_right(t_cub *cub)
{
	t_f32	x;
	t_f32	y;

	x = cub->player->grid_x;
	y = cub->player->grid_y;
	x += (sin(cub->player->angle + (M_PI / 2)) * -1) * SPEED;
	y += cos(cub->player->angle + (M_PI / 2)) * SPEED;
	if (cub_player_can_go(cub, x, y))
	{
		cub->player->grid_x = x;
		cub->player->grid_y = y;
	}
}

static void	fs_move_player_forward(t_cub *cub)
{		
	t_f32	x;
	t_f32	y;

	x = cub->player->grid_x;
	y = cub->player->grid_y;
	x += (sin(cub->player->angle) * -1) * SPEED;
	y += cos(cub->player->angle) * SPEED;
	if (cub_player_can_go(cub, x, y))
	{
		cub->player->grid_x = x;
		cub->player->grid_y = y;
	}
}

static void	fs_move_player_backward(t_cub *cub)
{
	t_f32	x;
	t_f32	y;

	x = cub->player->grid_x;
	y = cub->player->grid_y;
	x += sin(cub->player->angle) * SPEED;
	y += (cos(cub->player->angle) * -1) * SPEED;
	if (cub_player_can_go(cub, x, y))
	{
		cub->player->grid_x = x;
		cub->player->grid_y = y;
	}
}

void	cub_move_player(t_cub *cub, t_u16 key)
{
	cub->world->update = true;
	if (key == XK_a)
		fs_move_player_left(cub);
	if (key == XK_d)
		fs_move_player_right(cub);
	if (key == XK_w)
		fs_move_player_forward(cub);
	if (key == XK_s)
		fs_move_player_backward(cub);
}
