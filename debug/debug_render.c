#include "../inc/cub.h"

char	*dg_get_pixel(t_buffer *bs, t_u16 x, t_u16 y)
{
	int	pixel;

	pixel = (y * bs->line_bytes) + (x * 4);
	return (&bs->buffer[pixel]);
}

void	dg_copy_pixel(char *dest, char *src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = src[3];
}

void	*dg_get_texture(t_cub *cub, t_texture id)
{
	if (id == TEXTURE_EAST)
		return (cub->img->ea_buf);
	if (id == TEXTURE_WEST)
		return (cub->img->we_buf);
	if (id == TEXTURE_NORTH)
		return (cub->img->no_buf);
	if (id == TEXTURE_SOUTH)
		return (cub->img->so_buf);
	return (0);
}

void	dg_get_col_img(t_cub *cub, int col, t_ray *ray)
{
	t_buffer	*bs;
	char		*img;
	char		*pix;
	t_f64		size;
	t_f64		lineheight;
	int			drawstart;
	int			drawend;
	t_f64		step;
	t_f64		texpos;
	
	ray->length *= cos(cub->player->angle - ray->angle);
	lineheight = (t_f64)(HEIGHT / ray->length) * 64.0;
	drawstart = -lineheight / 2 + HEIGHT / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + HEIGHT / 2;
	if (drawend >= HEIGHT)
		drawend = HEIGHT;
	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->display->img, \
			&bs->pixel_bits, &bs->line_bytes, &bs->endian);

	size = lineheight / 64.0;
	step = (64.0 / lineheight);
	if (drawstart + lineheight > HEIGHT)
	{
		// step = (64.0 / lineheight) / 0.9;
		texpos = ((drawstart - HEIGHT / 2 + lineheight) * step) - 32.0;
	}
	else
	{
		// step = (64.0 / lineheight);
		texpos = 0;
	}
	printf("Lineheight: %f	DrawStart: %d	DrawEnd: %d\n",lineheight, drawstart, drawend);
	printf("Size: %f\n", size);

	while (drawstart < drawend)
	{
		if (ray->texture == TEXTURE_NORTH || ray->texture == TEXTURE_SOUTH)
			img = dg_get_pixel(dg_get_texture(cub, ray->texture), ray->target_x % 64, texpos);
		else
			img = dg_get_pixel(dg_get_texture(cub, ray->texture), ray->target_y % 64, texpos);
		pix = dg_get_pixel(bs, col, drawstart);
		dg_copy_pixel(pix, img);
		texpos += step;
		drawstart++;
		// printf("drawstart: %d, drawend:%d ,size:%f, y:%d\n", drawstart, drawend, size, y);
	}
	free(bs);
}

void	dg_build_render(t_cub *cub)
{
	int		i;
	t_ray	*ray;

	ray = cub->rays;
	i = 0;
	while (i < RAYS)
	{
		printf("ray: %d / target_x: %d / lenght: %f\n", ray[i].column_index, ray[i].target_x, ray[i].length);
		dg_get_col_img(cub, i, &ray[i]);
		i++;
	}
}
