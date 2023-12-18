/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:29 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/18 23:11:41 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

char	*ft_writing(const char *str, int n);

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
