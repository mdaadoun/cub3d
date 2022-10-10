#include "../inc/cub.h"

void	*fs_open_img(t_cub *cub, char *path)
{
	void	*ptr;
	int		wid;
	int		hei;

	wid = 64;
	hei = 64;
	ptr = mlx_xpm_file_to_image(cub->display->win, path, &wid, &hei);
	if (!ptr)
		cub_free_before_exit(cub, ERROR_IMG);
	return (ptr);
}

void	cub_load_img(t_cub *cub)
{
	if (cub->data->imgpath_no)
		cub->img->no = fs_open_img(cub, cub->data->imgpath_no);
	if (cub->data->imgpath_so)
		cub->img->so = fs_open_img(cub, cub->data->imgpath_so);
	if (cub->data->imgpath_ea)
		cub->img->ea = fs_open_img(cub, cub->data->imgpath_ea);
	if (cub->data->imgpath_we)
		cub->img->we = fs_open_img(cub, cub->data->imgpath_we);
}

void	cub_free_img(t_cub *cub)
{
	if (cub->img->no)
		mlx_destroy_image(cub->display->mlx, cub->img->no);
	if (cub->img->so)
		mlx_destroy_image(cub->display->mlx, cub->img->so);
	if (cub->img->ea)
		mlx_destroy_image(cub->display->mlx, cub->img->ea);
	if (cub->img->we)
		mlx_destroy_image(cub->display->mlx, cub->img->we);
	free(cub->img);
	cub->img = 0;
}
