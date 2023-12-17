/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2023/12/17 18:42:26 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MARKSPEC "\033[35m\\"
#define MARKZERO "\033[31m\\"
#define MARKOUT "\033[2m"
#define MARKDOWN "\033[0m"

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
			size += ft_strlen(MARKSPEC) + 1;
		else if (ft_isoctal(str[i]))
			size += ft_strlen(MARKSPEC) + 3;
		else
			size += ft_strlen(MARKDOWN) + 1;
		i += ft_lookahead(str, n - i);
	}
	return (size);
}

int	ft_mark_writing(char *dest, const int c)
{
	if (c == '\0')
		return (ft_strcat(dest, MARKZERO));
	if (!ft_isprint(c))
		return (ft_strcat(dest, MARKSPEC));
	else
		return (ft_strcat(dest, MARKDOWN));
}

int	ft_convert_writing(char *dest, const int c)
{
	const char	*bpreference = "abtnvfr";
	char		backprint[2];
	char		octal[4];

	ft_bzero(backprint, 2);
	ft_bzero(octal, 4);
	if (c == '\0')
		ft_strcat(dest, "0");
	if (ft_isbackprint(c))
	{
		backprint[0] = bpreference[c - 7];
		ft_strcat(dest, backprint);
		return (1);
	}
	else if (c == '\177')
		ft_cpy(octal, "DEL", 3);
	else if (!ft_isprint(c))
	{
		octal[0] = ((c >> 6) & 7) + '0';
		octal[1] = ((c >> 3) & 7) + '0';
		octal[2] = ((c >> 0) & 7) + '0';
	}
	ft_strcat(dest, octal);
	return (1);
}

int	ft_construct_writing(char *dest, const char *str, int n)
{
	const int	strlen = ft_strlen(str);
	int			spec;
	int			i;
	int			fellows;

	i = 0;
	while (n--)
	{
		fellows = ft_lookahead(&str[i], n);
		if (n == strlen)
			dest += ft_strcat(dest, MARKOUT);
		dest += ft_mark_writing(dest, str[i]);
		while (fellows--)
		{
			if (!ft_isprint(str[i]))
				dest += ft_convert_writing(dest, str[i]);
			dest += ft_cpy(dest, &str[i], 1);
			i++;
		}
	}
	ft_strcat(dest, MARKDOWN);
	ft_strcat(dest, "\0");
	return (i);
}

char	*ft_writing(const char *str, int n)
{
	char		*outstr;
	const int	strlen = ft_strlen(str);
	int			size;

	if (n == 0)
		n = strlen;
	else if (n == -1)
		n = strlen + 1;
	size = ft_size_converted(str, n) + ft_strlen(MARKDOWN);
	if (n > strlen + 1)
		size += ft_strlen (MARKOUT);
	outstr = (char *)malloc(size + 1);
	if (outstr == NULL)
		return (NULL);
	outstr[size] = '\0';
	return (outstr);
}

	// if (size != ft_construct_writing(outstr, str, n))
	// 	ft_putstr("warning: size diff");