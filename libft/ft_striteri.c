/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaadoun <mdaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:23:02 by mdaadoun          #+#    #+#             */
/*   Updated: 2022/09/22 12:47:56 by dlaidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Apply the f function to each char of the string s (without return)
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
