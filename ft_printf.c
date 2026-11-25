/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhsikko <imhsikko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:34:31 by username          #+#    #+#             */
/*   Updated: 2026/11/25 18:54:45 by imhsikko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unknown(char f)
{
	int	check;

	check = ft_print_char('%');
	if (check == -1)
		return (-1);
	if (ft_print_char(f) == -1)
		return (-1);
	return (check + 1);
}

static int	printf_format(char f, va_list ap)
{
	if (f == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (f == 'd' || f == 'i')
		return (ft_print_digit(va_arg(ap, int), "0123456789"));
	if (f == 'u')
		return (ft_printnbr_base(va_arg(ap, unsigned int), "0123456789"));
	if (f == 'x')
		return (ft_printnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (f == 'X')
		return (ft_printnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (f == 'p')
		return (ft_print_ptr(va_arg(ap, void *), "0123456789abcdef"));
	if (f == '%')
		return (ft_print_char(f));
	return (print_unknown(f));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		check;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
			check = -1;
		else if (*format == '%')
			check = printf_format(*(++format), ap);
		else
			check = ft_print_char(*format);
		if (check == -1)
		{
			count = -1;
			break ;
		}
		count += check;
		format++;
	}
	va_end(ap);
	return (count);
}
