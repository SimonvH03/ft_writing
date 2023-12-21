/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:29 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/21 22:39:35 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_writing(const char *str, int n);

int	main(void)
{
	const char	*str1 = "line\tline\nline\0hidehide\n\0\tab\tab";
	char		*tmp;

	tmp = ft_writing(str1, 32);
	printf("\nft_writing:	%s\n\n", tmp);
	free(tmp);
	return (0);
}
