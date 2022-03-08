/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmerrill <dmerrill@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:44:22 by dmerrill          #+#    #+#             */
/*   Updated: 2022/01/12 13:45:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		free(s);
	}
	while (*s)
	{
		ft_putchar(*s);
		s++;
		i++;
	}
	return (i);
}
