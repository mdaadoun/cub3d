#include "../inc/cub.h"

void dda_algo(t_buffer *bs, t_line *line, t_color *color)
{
	float x,y,dx,dy,step,i;
  
	dx = abs(line->x2 - line->x1);
	dy = abs(line->y2 - line->y1);
	if(dx >= dy)
		step = dx;
	else
		step = dy;
	dx = dx / step;
	dy = dy / step;

	x = line->x1;
	y = line->y1;
	i = 1;
	while(i <= step)
	{
		cub_draw_pixel(bs, x, y, color);
		if (x < line->x2)
			x = x + dx;
		else
			x = x - dx;
		if (y < line->y2)
			y = y + dy;
		else
			y = y - dy;
		i = i + 1;
	}
}

void	db_draw_line(t_cub *cub, t_line	*line, t_color *color)
{
	// t_u16		x;
	// t_u16		y;
	t_buffer	*bs;

	bs = (t_buffer *) cub_alloc(cub, sizeof(t_buffer), 1);
	bs->buffer = mlx_get_data_addr(cub->display->img, &bs->pixel_bits, &bs->line_bytes, &bs->endian);
	dda_algo(bs, line, color);
	free(bs);
}

static void	fs_display_vision(t_cub *cub)
{
	t_line	line_dir;
	t_line	fov_left;
	t_line	fov_right;
	t_color	color;

	color.b = 0;
	color.r = 255;
	color.g = 255;
	color.t = 0;
	line_dir.x1 = (cub->player->map_x + cub->player->grid_x) * GRID;
	line_dir.y1 = (cub->player->map_y + cub->player->grid_y) * GRID;
	line_dir.x2 = (((cub->player->map_x + cub->player->grid_x) - sin(cub->player->angle)) * (GRID));
	line_dir.y2 = (((cub->player->map_y + cub->player->grid_y) + cos(cub->player->angle)) * (GRID));
	fov_left.x1 = (cub->player->map_x + cub->player->grid_x) * GRID;
	fov_left.y1 = (cub->player->map_y + cub->player->grid_y) * GRID;
	fov_left.x2 = (((cub->player->map_x + cub->player->grid_x) - sin(cub->player->angle - FOV / 2)) * (GRID));
	fov_left.y2 = (((cub->player->map_y + cub->player->grid_y) + cos(cub->player->angle - FOV / 2)) * (GRID));
	fov_right.x1 = (cub->player->map_x + cub->player->grid_x) * GRID;
	fov_right.y1 = (cub->player->map_y + cub->player->grid_y) * GRID;
	fov_right.x2 = (((cub->player->map_x + cub->player->grid_x) - sin(cub->player->angle + FOV / 2)) * (GRID));
	fov_right.y2 = (((cub->player->map_y + cub->player->grid_y) + cos(cub->player->angle + FOV / 2)) * (GRID));
	db_draw_line(cub, &line_dir, &color);
	db_draw_line(cub, &fov_left, &color);
	db_draw_line(cub, &fov_right, &color);
	ft_printf("vision: x1:%d, y1:%d, x2:%d, y2:%d\n", line_dir.x1, line_dir.y1, line_dir.x2, line_dir.y2);
}

#include <stdio.h>
static void fs_display_rays(t_cub *cub)
{
	t_ray 	*ray;
	t_u16	i;

	i = 0;
	ray = cub->rays;
	while (i < WIDTH)
	{
		printf("id:%d, angle:%f | ", ray[i].column_index, ray[i].angle);
		i++;
	}
	printf("\n");
}

int	dg_game_loop(t_cub *cub)
{
	if (cub->world->update)
	{
		cub_cast_rays(cub);
		cub_draw_world(cub);
		dg_draw_map(cub, cub->map->arr);
		fs_display_vision(cub);
		fs_display_rays(cub);
		mlx_put_image_to_window(cub->display->mlx, cub->display->win, cub->display->img, 0, 0);
		cub->world->update = false;
	}
	// if (cub->player->update)
	// {
	// 	cub->player->update = false;
	// }

	return (0);
}