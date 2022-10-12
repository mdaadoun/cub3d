#include "../inc/cub.h"

static int	fs_close(t_cub *cub)
{
	cub_free_before_exit(cub, NO_ERROR);
	return (0);
}

static int	fs_key_hook(int keycode, t_cub *cub)
{
	if (keycode == XK_Escape)
		cub_free_before_exit(cub, NO_ERROR);
	else if (keycode == XK_a)
		cub_move_player(cub, XK_a);
	else if (keycode == XK_s)
		cub_move_player(cub, XK_s);
	else if (keycode == XK_d)
		cub_move_player(cub, XK_d);
	else if (keycode == XK_w)
		cub_move_player(cub, XK_w);
	else if (keycode == XK_Left)
	{
		cub->player->angle -= ROT_STEP;
		cub->world->update = true;
	}
	else if (keycode == XK_Right)
	{
		cub->player->angle += ROT_STEP;
		cub->world->update = true;
	}
	return (0);
}

void	cub_init_events(t_cub *cub)
{
	mlx_hook(cub->display->win, KeyPress, (1L << 0), fs_key_hook, cub);
	mlx_hook(cub->display->win, DestroyNotify, 1L << 17, fs_close, cub);
}
