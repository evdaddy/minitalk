/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmerrill <dmerrill@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:46:07 by dmerrill          #+#    #+#             */
/*   Updated: 2022/01/12 13:48:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

void	ft_putchar(char c);
int		ft_print_char(char c);
int		ft_print_str(char *s);
char	*ft_itoa_16(unsigned long long n);
int		ft_print_pointer(unsigned long long pointer);
int		ft_print_big_x(unsigned int n);
int		ft_print_x(unsigned int n);
int		ft_numlen(long long n);
int		ft_printf_unsgnd(unsigned int num);
int		ft_printf_decimal(int num);
int		ft_printf(const char *input, ...);

#endif
