/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:16:31 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/28 08:54:41 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void fs_draw_rectangle(t_win *win, t_rect *rect, t_color *color)
{
	ft_printf("Draw a rectangle to window!\n");
	(void) win;
	(void) rect;
	(void) color;
}

static void fs_draw_map(t_win *win, char **map)
{
	ft_printf("Draw map!\n");
	(void) win;
	(void) map;
}

static void fs_draw_player(t_win *win, t_player *player)
{
	ft_printf("Draw player!\n");
	(void) win;
	(void) player;
}

void	cub_draw_world(t_cub *cub)
{
	fs_draw_rectangle(cub->win, cub->world->cel_rect, cub->world->cel_color);
	fs_draw_rectangle(cub->win, cub->world->flr_rect, cub->world->flr_color);
	fs_draw_map(cub->win, cub->map);
	fs_draw_player(cub->win, cub->player);
}
