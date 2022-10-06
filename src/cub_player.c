#include "../inc/cub.h"

void	cub_rotate_player(t_cub *cub, t_u16 key)
{
	ft_printf("rotate %d\n", key);
	(void) cub;
}

void	cub_move_player(t_cub *cub, t_u16 key)
{
	cub->world->update = true;
	ft_printf("move %d\n", key);
	if (key == XK_a)
	{
		cub->player->pos_x -= 0.1;
		if (cub->player->pos_x == 0.0)
		{
			cub->player->pos_x = 1.0;
			cub->player->map_x -= 1;
		}
	}
	if (key == XK_d)
	{
		cub->player->pos_x += 0.1;
		if (cub->player->pos_x == 1.0)
		{
			cub->player->pos_x = 0.0;
			cub->player->map_x += 1;
		}
	}
	if (key == XK_w)
	{
		cub->player->pos_y -= 0.1;
		if (cub->player->pos_y == 0.0)
		{
			cub->player->pos_y = 1.0;
			cub->player->map_y -= 1;
		}
	}
	if (key == XK_s)
	{
		cub->player->pos_y += 0.1;
		if (cub->player->pos_y == 1.0)
		{
			cub->player->pos_y = 0.0;
			cub->player->map_y += 1;
		}
	}
	(void) cub;
}
