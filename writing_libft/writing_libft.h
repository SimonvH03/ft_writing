/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:30:54 by simon             #+#    #+#             */
/*   Updated: 2023/12/18 22:57:42 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITING_LIBFT_H
# define WRITING_LIBFT_H
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
int		ft_isprint(int c);
int		ft_charcat(char *dest, const int c);
int		ft_strcat(char *dest, const char *src);
int		ft_strlen(const char *str);

#endif