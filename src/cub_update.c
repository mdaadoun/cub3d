#include "../inc/cub.h"

int cub_game_loop(t_cub *cub)
{
	if (cub->world->update)
	{
		cub_draw_world(cub);
		ft_printf("update and display \nPlayer position map:x:%d y:%d\n", cub->player->x, cub->player->y);
		cub->world->update = false;
	}
	return (0);
}
