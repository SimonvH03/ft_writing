/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:28:45 by simon             #+#    #+#             */
/*   Updated: 2023/12/17 18:37:08 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITING_H
# define FT_WRITING_H
# include "writing_libft/writing_libft.h"
# include <stdarg.h>
# include <unistd.h>

char	*ft_writing(const char *str, int n);

int		ft_size_converted(const char *str, int n);
int		ft_mark_writing(char *dest, const int c);
int		ft_convert_writing(char *dest, const int c);
int		ft_construct_writing(char *dest, const char *str, int n);

int		ft_isbackprint(int c);
int		ft_isoctal(int c);
int		ft_lookahead(const char *str, int n);

#endif