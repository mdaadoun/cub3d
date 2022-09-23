/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:23:04 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/23 11:28:39 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"


static t_u8	fs_save_data(t_cub *cub, char *line, t_u8 count)
{
	char **split;
	t_data		*data;

	data = cub->data;
	count++;
	if (line[0] == '\n')
		return (count);
	split = ft_split(line, ' ');
	if (split[2])
		cub_free_before_exit(cub, ERROR_FORMAT);
	if (line[0] == 'F' && line[1] == ' ')
		data->color_F = split[1];
	else if (line[0] == 'C' && line[1] == ' ')
		data->color_C = split[1];
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		data->imgpath_EA = split[1];
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		data->imgpath_NO = split[1];
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		data->imgpath_EA = split[1];
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		data->imgpath_WE = split[1];
	else
		count--;
	free(split);
	return (count);
}

void	cub_parse_data(t_cub *cub)
{
	t_list_str	*data_list;
	t_u8		count;

	data_list = cub->data->filedata;
	while (data_list)
	{
		count = fs_save_data(cub, data_list->str, count);
		data_list = data_list->next;
	}
	if (count != 6)
		cub_free_before_exit(cub, ERROR_FORMAT);
	cub_build_map(cub);
}
