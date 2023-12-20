/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2023/12/20 17:35:22 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing.h"

int	ft_isbackprint(char c)
{
	return (c >= '\a' && c <= '\r');
}

int	ft_isoctal(char c)
{
	return (!ft_isprint(c) && !ft_isbackprint(c));
}

int	ft_lookahead(const char *str, int n)
{
	int	i;

	i = 0;
	if (n-- && str[i] == '\0')
		while (str[i] == '\0')
			i++;
	else if (n-- && ft_isprint(str[i]))
		while (ft_isprint(str[i]))
			i++;
	else if (n-- && ft_isbackprint(str[i]))
		while (ft_isbackprint(str[i]))
			i++;
	else if (n-- && ft_isoctal(str[i]))
		while (ft_isoctal(str[i]))
			i++;
	return (i);
}
