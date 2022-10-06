#include "../inc/cub.h"

void	fs_set_color(t_i8 index, t_color *color, t_i8 col)
{
	if (index == 0)
		color->R = col;
	else if (index == 1)
		color->G = col;
	else if (index == 2)
		color->B = col;
}

bool	fs_check_set_colors(t_cub *cub, t_color *color, char *colstr)
{
	char	**colors;
	t_u16	i;
	t_i16	col;

	colors = ft_split(colstr, ',');
	i = 0;
	while (colors[i])
	{
		col = ft_atoi(colors[i]);
		if (col < 0 || col > 255)
			cub_free_before_exit(cub, ERROR_FORMAT);
		fs_set_color(i, color, col);
		i++;
	}
	if (i != 3)
		cub_free_before_exit(cub, ERROR_FORMAT);
	cub_free_strarr(colors);
	return (true);
}

void	fs_set_colors_rectangles(t_cub *cub)
{
	t_rect	*rectf;
	t_rect	*rectc;

	rectf = (t_rect *)cub_alloc(cub, sizeof(t_rect), 1);
	rectc = (t_rect *)cub_alloc(cub, sizeof(t_rect), 1);
	rectc->height = HEIGHT / 2;
	rectc->width = WIDTH;
	rectc->x = 0;
	rectc->y = 0;
	rectf->height = HEIGHT / 2;
	rectf->width = WIDTH;
	rectf->x = 0;
	rectf->y = HEIGHT / 2;
	cub->world->flr_rect = rectf;
	cub->world->cel_rect = rectc;
}

void	cub_init_colors(t_cub *cub)
{
	char		*colc;
	char		*colf;

	colc = cub->data->color_c;
	colf = cub->data->color_f;
	if (!fs_check_set_colors(cub, cub->world->cel_color, colc))
		cub_free_before_exit(cub, ERROR_FORMAT);
	if (!fs_check_set_colors(cub, cub->world->flr_color, colf))
		cub_free_before_exit(cub, ERROR_FORMAT);
	fs_set_colors_rectangles(cub);
}
