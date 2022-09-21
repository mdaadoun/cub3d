/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:44:08 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/21 15:33:18 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	*cub_get_error_msg(t_errkey errkey)
{
	if (errkey == ERROR_MALLOC)
		return (MSG_ERROR_MALLOC);
	else if (errkey == ERROR_PARAMS)
		return (MSG_ERROR_PARAMS);
	else if (errkey == ERROR_PARAMS)
		return (MSG_ERROR_PARAMS);
	else if (errkey == ERROR_FILE_EXT)
		return (MSG_ERROR_FILE_EXT);
	else if (errkey == NO_ERROR)
		return (MSG_SUCCESS_EXIT);
	return (NULL);
}

int	cub_get_error_length(t_errkey errkey)
{
	char	*str;
	int		len;

	len = 0;
	str = NULL;
	if (errkey == ERROR_MALLOC)
		str = MSG_ERROR_MALLOC;
	else if (errkey == ERROR_PARAMS)
		str = MSG_ERROR_PARAMS;
	else if (errkey == ERROR_FILE_EXT)
		str = MSG_ERROR_FILE_EXT;
	else if (errkey == NO_ERROR)
		str = MSG_SUCCESS_EXIT;
	if (str)
		while (str[len])
			len++;
	return (len);
}


void	cub_print_error(t_errkey errkey, t_u8 out)
{
	if (out == 2)
		write(out, "\e[0;35mError\n", 13);
	else
		write(out, "\e[0;32m", 7);
	write(out, cub_get_error_msg(errkey), cub_get_error_length(errkey));
	write(out, "\e[m\n", 4);
}
