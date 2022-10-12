#include "../inc/cub.h"

char	*dg_get_pixel(t_buffer *bs, t_u16 x, t_u16 y)
{
	int	pixel;

	pixel = (y * bs->line_bytes) + (x * 4);
	return (&bs->buffer[pixel]);
}

void	dg_copy_pixel(char *dest, char *src, int mul)
{
	while (mul != 0)
	{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = src[3];
	dest = &dest[4];
	mul--;
	}
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
	char		*pix;
	int			y;
	t_f64		size;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			a;
	int			b;
	int			c;
	t_f32		ratio;
	t_f32		count_ratio;

	lineheight = (int)(HEIGHT / ray->length) * 64;
	drawstart = -lineheight / 2 + HEIGHT / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + HEIGHT / 2;
	if (drawend >= HEIGHT)
		drawend = HEIGHT - 1;
	printf("Lineheight: %d	DrawStart: %d	DrawEnd: %d\n",lineheight, drawstart, drawend);
	size = lineheight / 64;
	if (size == 0)
		size = 1;
	printf("Size: %f\n", size);
	y = 0;
	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->display->img, \
			&bs->pixel_bits, &bs->line_bytes, &bs->endian);
	a = size * 64;
	if (a > HEIGHT)
	{
		b = a - HEIGHT;
		y = (b / 2) / size;
		c = y;
	}
	printf("Y: %d	64 - C:%d\n", y, 64 - c);
	ratio = ((drawend - drawstart) / 64);
	count_ratio = 0;
	while (drawstart < drawend)
	{
		pix = dg_get_pixel(bs, col, drawstart);
		if (ray->texture == TEXTURE_NORTH || ray->texture == TEXTURE_SOUTH)
			dg_copy_pixel(pix, dg_get_pixel(dg_get_texture(cub, ray->texture), \
					ray->target_x % 64, y), size);
		else
			dg_copy_pixel(pix, dg_get_pixel(dg_get_texture(cub, ray->texture), \
					ray->target_y % 64, y), size);
		drawstart++;
		if (count_ratio == ratio)
		{
			y++;
			count_ratio = 0;
		}
		count_ratio += 1;
		printf("drawstart: %d y:%d\n", drawstart, y);
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
		printf("ray: %d / target_x: %d / lenght: %f\n", i, ray[i].target_x, ray[i].length);
		dg_get_col_img(cub, i, &ray[i]);
		i++;
	}
}
