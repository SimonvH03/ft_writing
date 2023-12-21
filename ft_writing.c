/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2023/12/21 15:34:15 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing.h"

int	ft_convert_writing(char *dest, const char c)
{
	const char	*bp_reference = "abtnvfr";
	char		backprint[2];
	char		octal[4];

	ft_bzero(backprint, 2);
	ft_bzero(octal, 4);
	ft_charcat(dest, '\\');
	if (c == '\0')
		ft_charcat(dest, '0');
	else if (ft_isbackprint(c))
	{
		backprint[0] = bp_reference[c - '\a'];
		ft_strcat(dest, backprint);
		return (1);
	}
	else if (c == '\177')
		ft_strcat(octal, "DEL");
	else if (ft_isoctal(c))
	{
		octal[0] = ((c >> 6) & 7) + '0';
		octal[1] = ((c >> 3) & 7) + '0';
		octal[2] = ((c >> 0) & 7) + '0';
	}
	ft_strcat(dest, octal);
	return (1);
}

int	ft_mark_writing(char *dest, const char *str, int i)
{
	const int	strlen = ft_strlen(str);

	if (str[i] == '\0')
		return (ft_strcat(dest, MARKZERO));
	else if (!ft_isprint(str[i]))
		return (ft_strcat(dest, MARKSPEC));
	else if (i < strlen)
		return (ft_strcat(dest, MARKDOWN));
	else
		return (ft_strcat(dest, MARKOUT));
}

int	ft_construct_writing(char *dest, const char *str, int n)
{
	int			fellows;
	int			i;

	i = 0;
	while (i < n)
	{
		ft_mark_writing(dest, str, i);
		fellows = ft_lookahead(&str[i], n - i);
		while (fellows--)
		{
			if (!ft_isprint(str[i]))
				ft_convert_writing(dest, str[i]);
			else
				ft_charcat(dest, str[i]);
			i++;
		}
	}
	ft_strcat(dest, MARKDOWN);
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
	outstr = (char *)malloc((size + 1) * sizeof(char));
	if (outstr == NULL)
		return (NULL);
	outstr[size] = '\0';
	ft_construct_writing(outstr, str, n);
	return (outstr);
}
