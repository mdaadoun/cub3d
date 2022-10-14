/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:26 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/10/14 07:00:31 by dlaidet          ###   ########.fr       */
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
		ft_free_tab_string(split);
		cub_free_before_exit(cub, ERROR_FORMAT);
	}
	ret = split[1];
	free(split[0]);
	free(split);
	return (ret);
}

static void	fs_check_set_config(t_cub *cub, char *line, char **str_ptr)
{
	char	*str;

	str = fs_split_and_trim(cub, line);
	if (*str_ptr)
		cub_free_before_exit(cub, ERROR_FORMAT);
	*str_ptr = str;
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
		fs_check_set_config(cub, line, &data->color_f);
	else if (len >= 2 && line[0] == 'C' && line[1] == ' ')
		fs_check_set_config(cub, line, &data->color_c);
	else if (len >= 3 && line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		fs_check_set_config(cub, line, &data->imgpath_ea);
	else if (len >= 3 && line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		fs_check_set_config(cub, line, &data->imgpath_no);
	else if (len >= 3 && line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		fs_check_set_config(cub, line, &data->imgpath_so);
	else if (len >= 3 && line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		fs_check_set_config(cub, line, &data->imgpath_we);
	else
		cub_free_before_exit(cub, ERROR_FORMAT);
	return (count);
}

t_list_str	*cub_set_config(t_cub *cub)
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
	return (data_list);
}
