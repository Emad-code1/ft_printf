/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhsikko <imhsikko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:27:05 by username          #+#    #+#             */
/*   Updated: 2026/11/23 09:55:12 by imhsikko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_printnbr_base(size_t nb, const char *base)
{
	int		count;
	int		check;
	size_t	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		check = ft_printnbr_base(nb / base_len, base);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = ft_print_char(base[nb % base_len]);
	if (check == -1)
		return (-1);
	return (count + check);
}
