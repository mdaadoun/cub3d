#include "../inc/cub.h"

static void	fs_is_cub_file(t_cub *cub, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 'b')
		if (file[len - 2] == 'u')
			if (file[len - 3] == 'c')
				if (file[len - 4] == '.')
					return ;
	cub_free_before_exit(cub, ERROR_FILE);
}

static void	fs_build_filedata(t_cub *cub)
{
	t_list_str	*data;
	char		*line;
	int			fd;

	fd = open(cub->data->filepath, O_RDONLY);
	if (fd == -1)
		cub_free_before_exit(cub, ERROR_FILE);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		data = ft_lstnew_str(line);
		ft_lstadd_back_str(&cub->data->filedata, data);
	}
	close(fd);
}

/*
 *	Check if the given file is valid and build a structure from its content.
 */
void	cub_get_data(t_cub *cub, int ac, char **av)
{
	cub->data = (t_data *)cub_alloc(cub, 1, sizeof(t_data));
	if (ac != 2)
		cub_free_before_exit(cub, ERROR_PARAMS);
	fs_is_cub_file(cub, av[1]);
	cub->data->filepath = av[1];
	fs_build_filedata(cub);
}
