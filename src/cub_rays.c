/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:00 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/12 15:41:44 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	fs_set_texture(t_ray *ray)
{
	t_u16	x1;
	t_u16	y1;
	t_u16	x2;
	t_u16	y2;

	x1 = ray->prev_tgx / GRID;
	y1 = ray->prev_tgy / GRID;
	x2 = ray->target_x / GRID;
	y2 = ray->target_y / GRID;
	if (x1 == x2 && y1 < y2)
		ray->texture = TEXTURE_NORTH;
	if (x1 == x2 && y1 > y2)
		ray->texture = TEXTURE_SOUTH;
	if (x1 > x2 && y1 == y2)
		ray->texture = TEXTURE_EAST;
	if (x1 < x2 && y1 == y2)
		ray->texture = TEXTURE_WEST;
}

static bool	fs_is_wall(t_cub *cub, t_ray *ray)
{
	t_u16	x;
	t_u16	y;

	x = ray->target_x / GRID;
	y = ray->target_y / GRID;
	if (cub->map->arr[y][x] == '1')
		return (true);
	return (false);
}

static bool	fs_check_colision(t_cub *cub, t_ray *ray)
{
	ray->prev_tgx = ray->target_x;
	ray->prev_tgy = ray->target_y;
	ray->target_x = (((cub->player->map_x + cub->player->grid_x) \
	* GRID) - (sin(ray->angle) * ray->length));
	ray->target_y = (((cub->player->map_y + cub->player->grid_y) \
	* GRID) + (cos(ray->angle) * ray->length));
	if (fs_is_wall(cub, ray))
	{
		fs_set_texture(ray);
		return (true);
	}
	return (false);
}

void	cub_cast_rays(t_cub *cub)
{
	t_u16	idx;
	t_ray	*ray;
	t_f32	start_angle;

	start_angle = cub->player->angle - (cub->fov / 2);
	ray = cub->rays;
	idx = 0;
	while (idx != RAYS)
	{
		ray[idx].angle = start_angle;
		ray[idx].length = 1;
		ray[idx].column_index = idx + 1;
		while (!fs_check_colision(cub, &ray[idx]))
			ray[idx].length += 1;
		idx++;
		start_angle += cub->rays_steps;
	}
}
