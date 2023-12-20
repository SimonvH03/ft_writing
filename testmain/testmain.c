/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:29 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/20 23:00:16 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

char	*ft_writing(const char *str, int n);

int	main(void)
{
	const char	*str1 = "line\177line\033line\nline";
	char		*tmp;

	tmp = ft_writing(str1, 38);
	printf("\nft_writing:	%s\n", tmp);
	free(tmp);
	return (0);
}
