#include "../inc/cub.h"

static char	*fs_get_error_msg(t_errkey errkey)
{
	if (errkey == ERROR_MALLOC)
		return (MSG_ERROR_MALLOC);
	else if (errkey == ERROR_PARAMS)
		return (MSG_ERROR_PARAMS);
	else if (errkey == ERROR_FILE)
		return (MSG_ERROR_FILE);
	else if (errkey == ERROR_SCREEN)
		return (MSG_ERROR_SCREEN);
	else if (errkey == ERROR_FORMAT)
		return (MSG_ERROR_FORMAT);
	else if (errkey == ERROR_MAP)
		return (MSG_ERROR_MAP);
	else if (errkey == NO_ERROR)
		return (MSG_NO_ERROR);
	return (NULL);
}

static size_t	fs_get_error_length(t_errkey errkey)
{
	char	*str;
	size_t	len;

	len = 0;
	str = fs_get_error_msg(errkey);
	if (str)
		while (str[len])
			len++;
	return (len);
}

/*
 *	Print to stdout (1) or stderr (2) the error (or sucess) message. 
 */
void	cub_print_error(t_errkey errkey, t_u8 out)
{
	if (out == 2)
		write(out, "\e[0;35mError\n", 13);
	else
		write(out, "\e[0;32m", 7);
	write(out, fs_get_error_msg(errkey), fs_get_error_length(errkey));
	write(out, "\e[m\n", 4);
}
