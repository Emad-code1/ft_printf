/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhsikko <imhsikko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:26:54 by username          #+#    #+#             */
/*   Updated: 2026/11/23 10:14:27 by imhsikko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(int nb, const char *decimal)
{
	int	count;
	int	check;

	count = 0;
	if (nb == -2147483648)
		return (ft_print_str("-2147483648"));
	if (nb < 0)
	{
		check = ft_print_char('-');
		if (check == -1)
			return (-1);
		count += check;
		nb *= -1;
	}
	check = ft_printnbr_base(nb, decimal);
	if (check == -1)
		return (-1);
	return (count + check);
}
