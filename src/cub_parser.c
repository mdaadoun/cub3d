/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:23:04 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/23 15:05:55 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static char	**fs_split_and_trim(t_cub *cub, char *line)
{
	char	*trim;
	char	**split;

	trim = ft_strtrim(line, " \n");
	split = ft_split(trim, ' ');
	free(trim);
	if (split[2])
		cub_free_before_exit(cub, ERROR_FORMAT);
	return (split);
}

static t_u8	fs_save_data(t_cub *cub, char *line, t_u8 count)
{
	char		**split;
	t_data		*data;

	data = cub->data;
	count++;
	if (!ft_char_in_set(line[0], "\nFCSENSW"))
		cub_free_before_exit(cub, ERROR_FORMAT);
	split = fs_split_and_trim(cub, line);
	if (line[0] == 'F' && line[1] == ' ')
		data->color_F = split[1];
	else if (line[0] == 'C' && line[1] == ' ')
		data->color_C = split[1];
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		data->imgpath_EA = split[1];
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		data->imgpath_NO = split[1];
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		data->imgpath_SO = split[1];
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
