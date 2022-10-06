#include "../inc/cub.h"

void	cub_draw_pixel(t_buffer *bs, int x, int y, t_color *color)
{
	int	pixel;

	pixel = (y * bs->line_bytes) + (x * 4);
	bs->buffer[pixel + 0] = color->b;
	bs->buffer[pixel + 1] = color->g;
	bs->buffer[pixel + 2] = color->r;
	bs->buffer[pixel + 3] = color->t;
}

void	cub_draw_line(t_cub *cub, t_line *line, t_color *color)
{
	t_buffer	*bs;
	t_u16		x;
	t_u16		y;

	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->win->img, &bs->pixel_bits, &bs->line_bytes, &bs->endian);
	x = line->x1;
	y = line->y1;
	while (x != line->x2 && y != line->y2)
	{
		cub_draw_pixel(bs, x, y, color);
		if (x < line->x2)
			x++;
		if (x > line->x2)
			x--;
		if (y > line->y2)
			y--;
		if (y < line->y2)
			y++;
	}
	free(bs);
}

void	cub_draw_rectangle(t_cub *cub, t_rect *rect, t_color *color)
{
	t_buffer	*bs;
	int			x;
	int			y;

	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->win->img, &bs->pixel_bits, &bs->line_bytes, &bs->endian);
	x = 0;
	y = 0;
	while (x < rect->width && y < rect->height)
	{
		cub_draw_pixel(bs, rect->x + x, rect->y + y, color);
		if (x == rect->width - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	free(bs);
}

// static void fs_draw_cricle(t_win *win, , t_color *color)
// {
// 	ft_printf("Draw a line to window!\n");
// 	(void) line;
// 	(void) color;
// }
