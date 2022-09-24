/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:23:04 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/24 10:53:36 by dlaidet          ###   ########.fr       */
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

static char	*fs_flag_check(t_cub *cub, char *line, bool *flag)
{
	if (*flag == true)
		cub_free_before_exit(cub, ERROR_FORMAT);
	*flag = true;
	return (fs_split_and_trim(cub, line));
}

static t_u8	fs_save_data(t_cub *cub, char *line, t_u8 count)
{
	t_data			*data;
	size_t			len;

	data = cub->data;
	count++;
	len = ft_strlen(line);
	if (len >= 1 && line[0] == '\n')
		count--;
	else if (len >= 2 && line[0] == 'F' && line[1] == ' ')
		data->color_f = fs_flag_check(cub, line, &data->flag.f);
	else if (len >= 2 && line[0] == 'C' && line[1] == ' ')
		data->color_c = fs_flag_check(cub, line, &data->flag.c);
	else if (len >= 3 && line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		data->imgpath_ea = fs_flag_check(cub, line, &data->flag.ea);
	else if (len >= 3 && line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		data->imgpath_no = fs_flag_check(cub, line, &data->flag.no);
	else if (len >= 3 && line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		data->imgpath_so = fs_flag_check(cub, line, &data->flag.so);
	else if (len >= 3 && line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		data->imgpath_we = fs_flag_check(cub, line, &data->flag.we);
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
	cub_build_map(cub, data_list);
}
