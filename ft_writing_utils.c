/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2023/12/17 18:38:37 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MARKSPEC "\033[35m\\"
#define MAKEZERO "\033[31m\\0"
#define MARKOUT "\033[2m"
#define MARKDOWN "\033[0m"

int	ft_isbackprint(int c)
{
	return (c >= '\a' && c <= '\r');
}

int	ft_isoctal(int c)
{
	return (ft_isprint(c) && !ft_isbackprint(c));
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
