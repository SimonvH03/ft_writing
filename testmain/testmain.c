/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:29 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/21 23:08:05 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_writing(const char *str, int n);

int	main(void)
{
	const char	*str1 = "0\1771\1772\177\0\1774\1775\1776\177";
	char		*tmp;
	int			i;

	i = 0;
	while (i < 16)
	{
		tmp = ft_writing(str1, i);
		printf("\nft_writing(%d):	%s\n\n", i, tmp);
		free(tmp);
		i++;
	}
	return (0);
}
