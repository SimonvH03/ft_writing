/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:45:15 by simon             #+#    #+#             */
/*   Updated: 2023/12/18 23:35:52 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writing_libft.h"

int	ft_strcat(char *dest, const char *src)
{
	int			i;

	i = 0;
	while (dest[i])
		i++;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
