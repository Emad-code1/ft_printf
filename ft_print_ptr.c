/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhsikko <imhsikko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:27:01 by username          #+#    #+#             */
/*   Updated: 2026/11/23 10:08:03 by imhsikko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr, const char *hex)
{
	int	count;
	int	check;

	count = 0;
	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	check = ft_print_str("0x");
	if (check == -1)
		return (-1);
	count += check;
	check = ft_printnbr_base((unsigned long) ptr, hex);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
