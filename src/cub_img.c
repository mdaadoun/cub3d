#include "../inc/cub.h"

void	*fs_open_img(t_cub *cub, char *path)
{
	void	*ptr;
	int		wid;
	int		hei;

	ptr = mlx_xpm_file_to_image(cub->display->mlx, path, &wid, &hei);
	if (!ptr)
		cub_free_before_exit(cub, ERROR_IMG);
	return (ptr);
}

void	cub_load_img(t_cub *cub)
{
	t_buffer	*img;

	if (cub->data->imgpath_no)
	{
		cub->img->no = fs_open_img(cub, cub->data->imgpath_no);
		img = (t_buffer *)cub_alloc(cub, sizeof(t_buffer), 1);
		img->buffer = mlx_get_data_addr(cub->img->no, \
				&img->pixel_bits, &img->line_bytes, &img->endian);
		cub->img->no_buf = img;
	}
	if (cub->data->imgpath_so)
	{
		cub->img->so = fs_open_img(cub, cub->data->imgpath_so);
		img = (t_buffer *)cub_alloc(cub, sizeof(t_buffer), 1);
		img->buffer = mlx_get_data_addr(cub->img->so, \
				&img->pixel_bits, &img->line_bytes, &img->endian);
		cub->img->so_buf = img;
	}
	if (cub->data->imgpath_ea)
	{
		cub->img->ea = fs_open_img(cub, cub->data->imgpath_ea);
		img = (t_buffer *)cub_alloc(cub, sizeof(t_buffer), 1);
		img->buffer = mlx_get_data_addr(cub->img->ea, \
				&img->pixel_bits, &img->line_bytes, &img->endian);
		cub->img->ea_buf = img;
	}
	if (cub->data->imgpath_we)
	{
		cub->img->we = fs_open_img(cub, cub->data->imgpath_we);
		img = (t_buffer *)cub_alloc(cub, sizeof(t_buffer), 1);
		img->buffer = mlx_get_data_addr(cub->img->we, \
				&img->pixel_bits, &img->line_bytes, &img->endian);
		cub->img->we_buf = img;
	}
}

void	cub_free_img(t_cub *cub)
{
	if (cub->img->no)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->no);
		free(cub->img->no_buf);
	}
	if (cub->img->so)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->so);
		free(cub->img->so_buf);
	}
	if (cub->img->ea)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->ea);
		free(cub->img->ea_buf);
	}
	if (cub->img->we)
	{
		mlx_destroy_image(cub->display->mlx, cub->img->we);
		free(cub->img->we_buf);
	}
	free(cub->img);
	cub->img = 0;
}
