/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:29 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/20 22:40:17 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "../writing.h"

char	*ft_writing(const char *str, int n);

// int	main(void)
// {
// 	char dest[100];

// 	ft_bzero(dest, 100);
// 	ft_strcat_test(dest, "\033[35mline");
// 	ft_strcat_test(dest, "\033[31mline");
// 	printf("%s\n",dest);
// 	return (0);
// }

int	main(void)
{
	const char	*str1 = "line\177line\033line\nline";
	char		*tmp;

	tmp = ft_writing(str1, -1);
	printf("\nft_writing:	%s\n", tmp);
	printf("\ntmp adress:	%p\n", tmp);
	free(tmp);
	return (0);
}
