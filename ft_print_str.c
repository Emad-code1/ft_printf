/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhsikko <imhsikko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:27:09 by username          #+#    #+#             */
/*   Updated: 2026/11/23 15:49:29 by imhsikko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	count;
	int	check;

	count = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (*s)
	{
		check = ft_print_char(*s++);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}
