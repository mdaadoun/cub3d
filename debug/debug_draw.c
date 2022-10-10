#include "../inc/cub.h"

void	dg_draw_rectangle(t_cub *cub, t_rect *rect, t_color *color)
{
	t_buffer	*bs;
	int			x;
	int			y;

	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->display->img, \
			&bs->pixel_bits, &bs->line_bytes, &bs->endian);
	x = 0;
	y = 0;
	while (x < rect->width - 2 && y < rect->height - 2)
	{
		cub_draw_pixel(bs, rect->x + x, rect->y + y, color);
		if (x == rect->width - 3)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	free(bs);
}
