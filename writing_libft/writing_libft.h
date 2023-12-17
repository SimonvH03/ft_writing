/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:30:54 by simon             #+#    #+#             */
/*   Updated: 2023/12/17 18:45:45 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITING_LIBFT_H
# define WRITING_LIBFT_H
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
int		ft_cpy(char *out, const char *add, int n);
int		ft_isprint(int c);
int		ft_strcat(char *dest, const char *src);
int		ft_strlen(const char *c);

#endif