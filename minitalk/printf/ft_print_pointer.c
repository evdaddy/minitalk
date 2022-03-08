/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmerrill <dmerrill@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:38:24 by dmerrill          #+#    #+#             */
/*   Updated: 2022/01/12 13:39:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long long pointer)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_itoa_16(pointer);
	i += ft_print_str("0x") + ft_print_str(s);
	free(s);
	return (i);
}
