/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmerrill <dmerrill@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:00:57 by dmerrill          #+#    #+#             */
/*   Updated: 2022/01/12 14:10:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

static int	ft_treatment(char c, va_list args)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		char_count = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		char_count = ft_print_pointer(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		char_count = ft_printf_decimal(va_arg(args, int));
	else if (c == 'u')
		char_count += ft_printf_unsgnd(va_arg(args, unsigned int));
	else if (c == 'x')
		char_count = ft_print_x(va_arg(args, unsigned int));
	else if (c == 'X')
		char_count = ft_print_big_x(va_arg(args, unsigned int));
	else if (c == '%')
		char_count = ft_print_char('%');
	return (char_count);
}

static void	ft_notype(const char *input, int *char_count, int i)
{
	*char_count += 2;
	write(1, "%", 1);
	write(1, &input[i], 1);
}

static int	ft_main(const char *input, va_list args)
{
	int	i;
	int	char_count;

	i = 0;
	char_count = 0;
	while (1)
	{
		if (!input[i])
			break ;
		else if (input[i] == '%' && input[i + 1])
		{
			i++;
			if (ft_is_type(input[i]))
				char_count += ft_treatment(input[i], args);
			else if (input[++i])
				ft_notype(input, &char_count, i);
		}
		else if (input[i] != '%')
			char_count += ft_print_char(input[i]);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			char_count;

	char_count = 0;
	va_start(args, input);
	char_count += ft_main(input, args);
	va_end(args);
	return (char_count);
}
