/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2023/12/21 15:32:13 by simon            ###   ########.fr       */
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
	if (str[i] == '\0')
		while (n-- && str[i] == '\0')
			i++;
	else if (ft_isprint(str[i]))
		while (n-- && ft_isprint(str[i]))
			i++;
	else if (ft_isbackprint(str[i]))
		while (n-- && ft_isbackprint(str[i]))
			i++;
	else if (ft_isoctal(str[i]))
		while (n-- && ft_isoctal(str[i]))
			i++;
	return (i);
}

int	ft_size_converted(const char *str, int n)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < n)
	{
		if (str[i] == '\0')
			size += ft_strlen(MARKZERO);
		else if (ft_isbackprint(str[i]))
			size += ft_strlen(MARKSPEC);
		else if (ft_isoctal(str[i]))
			size += ft_strlen(MARKSPEC);
		else
			size += ft_strlen(MARKDOWN);
		size += ft_lookahead(&str[i], n - i);
		i += ft_lookahead(&str[i], n - i);
	}
	return (size);
}
