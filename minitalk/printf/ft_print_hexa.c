/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmerrill <dmerrill@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:43:02 by dmerrill          #+#    #+#             */
/*   Updated: 2022/01/12 16:17:38 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(unsigned long long n)
{
	size_t	i;

	i = 1;
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	putnbr(unsigned long long n, char *str)
{
	int	size;

	size = nbrlen(n);
	while (size > 0)
	{
		if (n % 16 > 9)
			str[size - 1] = (n % 16) + 87;
		else
			str[size - 1] = (n % 16) + 48;
		n = n / 16;
		size--;
	}
}

char	*ft_itoa_16(unsigned long long n)
{
	char		*str;
	long long	nbr;

	nbr = n;
	str = malloc(nbrlen(nbr) + 1);
	if (!str)
	{
		free (str);
		return (NULL);
	}
	str[nbrlen(nbr)] = '\0';
	putnbr(nbr, str);
	return (str);
}

int	ft_print_big_x(unsigned int n)
{
	char	*out;
	int		i;

	i = -1;
	out = ft_itoa_16(n);
	while (i++ < nbrlen(n) - 1)
	{
		if (out[i] <= 122 && out[i] >= 97)
			out[i] = out[i] - 32;
		write(1, &out[i], 1);
	}
	free(out);
	return (i);
}

int	ft_print_x(unsigned int n)
{
	char	*out;
	int		i;

	i = -1;
	out = ft_itoa_16(n);
	while (i++ < nbrlen(n) - 1)
		write(1, &out[i], 1);
	free(out);
	return (i);
}
