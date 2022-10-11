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
	char		*pix;
	int			y;

	y = 0;
	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->display->img, \
			&bs->pixel_bits, &bs->line_bytes, &bs->endian);
	while (y < 64)
	{
		pix = dg_get_pixel(bs, col, ((y * 2) + HEIGHT) / 2);
		dg_copy_pixel(pix, dg_get_pixel(dg_get_texture(cub, ray->texture), ray->target_x % 64, y));
		dg_copy_pixel(&pix[4], dg_get_pixel(dg_get_texture(cub, ray->texture), ray->target_x % 64, y));
		y++;
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
		printf("ray: %d			target_x: %d\n", i, ray[i].target_x);
		dg_get_col_img(cub, i, &ray[i]);
		i++;
	}
}
