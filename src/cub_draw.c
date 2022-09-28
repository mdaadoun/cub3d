#include "../inc/cub.h"

// static void fs_draw_map(t_win *win, char **map)
// {
// 	ft_printf("Draw map!\n");
// 	(void) win;
// 	(void) map;
// }

static void	fs_draw_player(t_win *win, t_player *player)
{
	ft_printf("Draw player!\n");
	(void) win;
	(void) player;
}

void	cub_draw_world(t_cub *cub)
{
	cub_draw_rectangle(cub->win, cub->world->cel_rect, cub->world->cel_color);
	cub_draw_rectangle(cub->win, cub->world->flr_rect, cub->world->flr_color);
	// fs_draw_map(cub->win, cub->map);
	fs_draw_player(cub->win, cub->player);
}
