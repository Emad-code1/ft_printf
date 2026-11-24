/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhsikko <imhsikko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:06:52 by username          #+#    #+#             */
/*   Updated: 2026/11/23 15:44:27 by imhsikko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_digit(int nb, const char *decimal);
int	ft_print_ptr(void *ptr, const char *hex);
int	ft_printnbr_base(size_t nb, const char *base);
int	ft_print_str(char *s);

#endif
