/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:02 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/12 15:54:31 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	fs_copy_pixel(char *dest, char *src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = src[3];
}

static void	fs_render_init(t_cub *cub, t_ray *ray, t_render *rend)
{
	ray->length *= cos(cub->player->angle - ray->angle);
	rend->bs = cub_alloc(cub, sizeof(t_buffer), 1);
	rend->bs->buffer = mlx_get_data_addr(cub->display->img, \
			&rend->bs->pixel_bits, &rend->bs->line_bytes, &rend->bs->endian);
	rend->lineheight = (t_f64)(HEIGHT / ray->length) * 64.0;
	rend->drawstart = -rend->lineheight / 2 + HEIGHT / 2;
	if (rend->drawstart < 0)
		rend->drawstart = 0;
	rend->drawend = rend->lineheight / 2 + HEIGHT / 2;
	if (rend->drawend >= HEIGHT)
		rend->drawend = HEIGHT;
	rend->step = (64.0 / rend->lineheight);
	if (rend->drawstart + rend->lineheight > HEIGHT)
		rend->texpos = ((rend->drawstart - HEIGHT / 2 \
				+ rend->lineheight) * rend->step) - 32.0;
	else
		rend->texpos = 0;
}

static void	fs_get_col_img(t_cub *cub, int col, t_ray *ray)
{
	t_render	rend;

	fs_render_init(cub, ray, &rend);
	while (rend.drawstart < rend.drawend)
	{
		if (ray->texture == TEXTURE_NORTH || ray->texture == TEXTURE_SOUTH)
			rend.img = cub_get_pixel(cub_get_texture(\
					cub, ray->texture), ray->target_x % 64, rend.texpos);
		else
			rend.img = cub_get_pixel(cub_get_texture(\
					cub, ray->texture), ray->target_y % 64, rend.texpos);
		rend.pix = cub_get_pixel(rend.bs, col, rend.drawstart);
		fs_copy_pixel(rend.pix, rend.img);
		rend.texpos += rend.step;
		rend.drawstart++;
	}
	free(rend.bs);
}

void	cub_build_render(t_cub *cub)
{
	int		i;
	t_ray	*ray;

	ray = cub->rays;
	i = 0;
	while (i < RAYS)
	{
		fs_get_col_img(cub, i, &ray[i]);
		i++;
	}
}
