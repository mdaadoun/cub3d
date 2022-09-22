/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_data_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:45:36 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/22 18:21:57 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static void	fs_is_cub(t_cub *cub, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 'b')
		if (file[len - 2] == 'u')
			if (file[len - 3] == 'c')
				if (file[len - 4] == '.')
					return ;
	cub_free_before_exit(cub, ERROR_FILE_EXT);
}

static void	fs_build_data_list(t_cub *cub)
{
	t_list_str	*data;
	char		*line;
	int			fd;

	fd = open(cub->data->data_file, O_RDONLY);
	if (fd == -1)
		cub_free_before_exit(cub, ERROR_FILE_MISSING);
	line = get_next_line(fd);
	data = ft_lstnew_str(line);
	cub->data->data_list = data;
	while (line)
	{
		line = get_next_line(fd);
		data = ft_lstnew_str(line);
		ft_lstadd_back_str(&cub->data->data_list, data);
	}
	close(fd);
	if (DEBUG) // TO REMOVE
		dg_lst_data(cub);
}

void	cub_data_set(t_cub *cub, int ac, char **av)
{
	cub->data = (t_data *)cub_alloc(cub, 1, sizeof(t_data));
	if (ac != 2)
		cub_free_before_exit(cub, ERROR_PARAMS);
	fs_is_cub(cub, av[1]);
	cub->data->data_file = av[1];
	fs_build_data_list(cub);
}
