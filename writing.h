/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:28:45 by simon             #+#    #+#             */
/*   Updated: 2023/12/21 15:13:25 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITING_H
# define WRITING_H
# include "writing_libft/writing_libft.h"
# include <stdlib.h>
# include <unistd.h>

# define MARKSPEC "\033[35m"
# define MARKZERO "\033[0;31m"
# define MARKOUT "\033[0;2m"
# define MARKDOWN "\033[0m"

char	*ft_writing(const char *str, int n);

int		ft_size_converted(const char *str, int n);
int		ft_mark_writing(char *dest, const char *str, int i);
int		ft_convert_writing(char *dest, const char c);
int		ft_construct_writing(char *dest, const char *str, int n);

int		ft_isbackprint(char c);
int		ft_isoctal(char c);
int		ft_lookahead(const char *str, int n);

#endif