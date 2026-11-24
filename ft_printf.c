/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhsikko <imhsikko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:34:31 by username          #+#    #+#             */
/*   Updated: 2026/11/23 15:07:08 by imhsikko         ###   ########.fr       */
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
	char	*decimal;
	char	*hex;
	char	*big_hex;

	decimal = "0123456789";
	hex = "0123456789abcdef";
	big_hex = "0123456789ABCDEF";
	if (f == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (f == 'd' || f == 'i')
		return (ft_print_digit(va_arg(ap, int), decimal));
	if (f == 'u')
		return (ft_printnbr_base(va_arg(ap, unsigned int), decimal));
	if (f == 'x')
		return (ft_printnbr_base(va_arg(ap, unsigned int), hex));
	if (f == 'X')
		return (ft_printnbr_base(va_arg(ap, unsigned int), big_hex));
	if (f == 'p')
		return (ft_print_ptr(va_arg(ap, void *), hex));
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
