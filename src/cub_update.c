#include "../inc/cub.h"
#include <stdio.h>

int	cub_game_loop(t_cub *cub)
{
	if (cub->world->update)
	{
		cub_draw_world(cub);
		mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
		ft_printf("update and display \nPlayer position map:x:%d y:%d\n", cub->player->map_x, cub->player->map_y);
		printf("update and display \nPlayer position :x:%f y:%f\n", cub->player->pos_x, cub->player->pos_y);
		printf("update and display \nPlayer angle : %f \n", cub->player->angle);
		cub->world->update = false;
	}
	return (0);
}
