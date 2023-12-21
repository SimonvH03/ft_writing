/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:29 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/21 15:38:43 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

char	*ft_writing(const char *str, int n);

int	main(void)
{
	const char	*str1 = "line\177\033line\a\b\nline\0hide\045hide\n\0\tab\tab";
	char		*tmp;

	tmp = ft_writing(str1, 36);
	printf("\nft_writing:	%s\n\n", tmp);
	free(tmp);
	return (0);
}
