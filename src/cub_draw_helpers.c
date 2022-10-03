#include "../inc/cub.h"

// static void fs_draw_line(t_win *win, t_line *line, t_color *color)
// {
// 	ft_printf("Draw a line to window!\n");
// 	(void) line;
// 	(void) color;
// }

void cub_draw_pixel(t_buffer *bs, int x, int y, t_color *color)
{
    int pixel;

	pixel = (y * bs->line_bytes) + (x * 4);
	bs->buffer[pixel + 0] = color->B;
	bs->buffer[pixel + 1] = color->G;
	bs->buffer[pixel + 2] = color->R;
	bs->buffer[pixel + 3] = color->T;
}


void	cub_draw_rectangle(t_cub *cub, t_rect *rect, t_color *color)
{
	t_buffer *bs;
	int x;
	int y;

	bs = cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->win->img, &bs->pixel_bits, &bs->line_bytes, &bs->endian);
	x = 0;
	y = 0;
	while (x < rect->width && y < rect->height)
	{
		cub_draw_pixel(bs, rect->x + x, rect->y + y, color);
		if ( x == rect->width - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	free(bs);
}

// static void fs_draw_cricle(t_win *win, , t_color *color)
// {
// 	ft_printf("Draw a line to window!\n");
// 	(void) line;
// 	(void) color;
// }
