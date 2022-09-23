/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:45:36 by dlaidet           #+#    #+#             */
/*   Updated: 2022/09/23 09:33:45 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	fs_build_data_list(t_cub *cub)
{
	t_list_str	*data;
	char		*line;
	int			fd;

	fd = open(cub->data->data_file, O_RDONLY);
	if (fd == -1)
		cub_free_before_exit(cub, ERROR_PATH);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		data = ft_lstnew_str(line);
		ft_lstadd_back_str(&cub->data->data_list, data);
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
	cub->data->data_file = av[1];
	fs_build_data_list(cub);
}
