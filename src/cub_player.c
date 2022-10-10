#include "../inc/cub.h"

static void	fs_move_player_left(t_cub *cub)
{
	cub->player->grid_x += sin(cub->player->angle + (M_PI / 2)) * SPEED;
	cub->player->grid_y += (cos(cub->player->angle + (M_PI / 2)) * -1) * SPEED;
}

static void	fs_move_player_right(t_cub *cub)
{
	cub->player->grid_x += (sin(cub->player->angle + (M_PI / 2)) * -1) * SPEED;
	cub->player->grid_y += cos(cub->player->angle + (M_PI / 2)) * SPEED;
}

static void	fs_move_player_forward(t_cub *cub)
{		
	cub->player->grid_x += (sin(cub->player->angle) * -1) * SPEED;
	cub->player->grid_y += cos(cub->player->angle) * SPEED;
}

static void	fs_move_player_backward(t_cub *cub)
{
	cub->player->grid_x += sin(cub->player->angle) * SPEED;
	cub->player->grid_y += (cos(cub->player->angle) * -1) * SPEED;
}

void	cub_move_player(t_cub *cub, t_u16 key)
{
	cub->world->update = true;
	if (key == XK_a)
		fs_move_player_left(cub);
	if (key == XK_d)
		fs_move_player_right(cub);
	if (key == XK_w)
		fs_move_player_forward(cub);
	if (key == XK_s)
		fs_move_player_backward(cub);
}
