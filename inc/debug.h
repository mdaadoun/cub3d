/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:28:35 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/21 14:29:51 by mdaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# ifndef DEBUG
# 	define DEBUG 1


/*
 *	Debug function:
*/

void	debug_print_arg(int ac, char **av);
void	debug_lst_data(t_cub *cub);

# endif
#endif