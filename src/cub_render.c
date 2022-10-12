/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:02 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/12 15:29:16 by mdaadoun         ###   ########.fr       */
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

static void	fs_get_col_img(t_cub *cub, int col, t_ray *ray)
{
	t_buffer	*bs;
	char		*img;
	char		*pix;
	t_f64		lineheight;
	int			drawstart;
	int			drawend;
	t_f64		step;
	t_f64		texpos;
	
	ray->length *= cos(cub->player->angle - ray->angle);
	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->display->img, \
			&bs->pixel_bits, &bs->line_bytes, &bs->endian);
	lineheight = (t_f64)(HEIGHT / ray->length) * 64.0;
	drawstart = -lineheight / 2 + HEIGHT / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + HEIGHT / 2;
	if (drawend >= HEIGHT)
		drawend = HEIGHT;
	step = (64.0 / lineheight);
	if (drawstart + lineheight > HEIGHT)
		texpos = ((drawstart - HEIGHT / 2 + lineheight) * step) - 32.0;
	else
		texpos = 0;
	while (drawstart < drawend)
	{
		if (ray->texture == TEXTURE_NORTH || ray->texture == TEXTURE_SOUTH)
			img = cub_get_pixel(cub_get_texture(cub, ray->texture), ray->target_x % 64, texpos);
		else
			img = cub_get_pixel(cub_get_texture(cub, ray->texture), ray->target_y % 64, texpos);
		pix = cub_get_pixel(bs, col, drawstart);
		fs_copy_pixel(pix, img);
		texpos += step;
		drawstart++;
	}
	free(bs);
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
