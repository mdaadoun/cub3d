/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:23:04 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/24 07:54:53 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static char	*fs_split_and_trim(t_cub *cub, char *line)
{
	char	*trim;
	char	**split;
	char	*ret;

	trim = ft_strtrim(line, " \n");
	if (ft_strlen(trim) == 0)
	{
		free(trim);
		return (NULL);
	}
	split = ft_split(trim, ' ');
	free(trim);
	if (split[2])
	{
		cub_free_split(split);
		cub_free_before_exit(cub, ERROR_FORMAT);
	}
	ret = split[1];
	free(split[0]);
	free(split);
	return (ret);
}

static t_u8	fs_save_data(t_cub *cub, char *line, t_u8 count)
{
	t_data		*data;
	size_t		len;

	data = cub->data;
	count++;
	len = ft_strlen(line);
	if (line[0] == '\n')
		count--;
	else if (len >= 2 && line[0] == 'F' && line[1] == ' ')
		data->color_F = fs_split_and_trim(cub, line);
	else if (len >= 2 && line[0] == 'C' && line[1] == ' ')
		data->color_C = fs_split_and_trim(cub, line);
	else if (len >= 3 && line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		data->imgpath_EA = fs_split_and_trim(cub, line);
	else if (len >= 3 && line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		data->imgpath_NO = fs_split_and_trim(cub, line);
	else if (len >= 3 && line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		data->imgpath_SO = fs_split_and_trim(cub, line);
	else if (len >= 3 && line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		data->imgpath_WE = fs_split_and_trim(cub, line);
	else
		cub_free_before_exit(cub, ERROR_FORMAT);
	return (count);
}

void	cub_parse_data(t_cub *cub)
{
	t_list_str	*data_list;
	t_u8		count;

	data_list = cub->data->filedata;
	count = 0;
	while (data_list->str)
	{
		count = fs_save_data(cub, data_list->str, count);
		data_list = data_list->next;
		if (count == 6)
			break ;
	}
	if (count != 6)
		cub_free_before_exit(cub, ERROR_FORMAT);
	cub_build_map(cub);
}
