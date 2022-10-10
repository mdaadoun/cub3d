#include "../inc/cub.h"

void	cub_draw_pixel(t_buffer *bs, t_u16 x, t_u16 y, t_color *color)
{
	int	pixel;

	pixel = (y * bs->line_bytes) + (x * 4);
	bs->buffer[pixel + 0] = color->b;
	bs->buffer[pixel + 1] = color->g;
	bs->buffer[pixel + 2] = color->r;
	bs->buffer[pixel + 3] = color->t;
}

void	cub_draw_rectangle(t_cub *cub, t_rect *rect, t_color *color)
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

void	cub_draw_world(t_cub *cub)
{
	cub_draw_rectangle(cub, cub->world->cel_rect, cub->world->cel_color);
	cub_draw_rectangle(cub, cub->world->flr_rect, cub->world->flr_color);
}
