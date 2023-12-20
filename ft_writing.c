/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:57:06 by simon             #+#    #+#             */
/*   Updated: 2023/12/20 17:31:03 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing.h"

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

int	ft_mark_writing(char *dest, const char c)
{
	if (c == '\0')
		return (ft_strcat(dest, MARKZERO));
	else if (!ft_isprint(c))
		return (ft_strcat(dest, MARKSPEC));
	else
		return (ft_strcat(dest, MARKDOWN));
}

int	ft_convert_writing(char *dest, const char c)
{
	const char	*bpreference = "abtnvfr";
	char		backprint[2];
	char		octal[4];

	ft_bzero(backprint, 2);
	ft_bzero(octal, 4);
	if (c == '\0')
		ft_charcat(dest, '0');
	if (ft_isbackprint(c))
	{
		backprint[0] = bpreference[c - 7];
		ft_strcat(dest, backprint);
		return (1);
	}
	else if (c == '\177')
		ft_strcat(octal, "DEL");
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
	int			fellows;
	int			i;

	i = 0;
	while (i < n)
	{
		if (i == strlen)
			ft_strcat(dest, MARKOUT);
		ft_mark_writing(dest, str[i]);
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
	printf("outstr adress:	%p\n", dest);
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
	outstr = (char *)malloc(size + 1);
	if (outstr == NULL)
		return (NULL);
	printf("outstr adress:	%p\n", outstr);
	outstr[size] = '\0';
	ft_construct_writing(outstr, str, n);
	return (outstr);
}

int	main(void)
{
	const char	*str1 = "line\nline\nline";
	char		*tmp;

	tmp = ft_writing(str1, -1);
	printf("\nft_writing:	%s\n", tmp);
	printf("\ntmp adress:	%p\n", tmp);
	free(tmp);
	return (0);
}
