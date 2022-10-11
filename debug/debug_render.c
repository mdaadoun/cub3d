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

void	dg_get_col_img(t_cub *cub)
{
	t_buffer	*bs;
	char		*pix;
	int			x;
	int			y;

	x = 12;
	y = 0;
	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->display->img, \
			&bs->pixel_bits, &bs->line_bytes, &bs->endian);
	while (x < 24 && y < 64)
	{
		pix = dg_get_pixel(bs, x + (2 * 64), y + (2 * 64));
		dg_copy_pixel(pix, dg_get_pixel(cub->img->ea_buf, x, y));
		if (x == 24 - 1)
		{
			x = 12;
			y++;
		}
		else
			x++;
	}
	free(bs);
}
