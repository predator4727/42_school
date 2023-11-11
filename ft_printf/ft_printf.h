/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:32:48 by aderugo           #+#    #+#             */
/*   Updated: 2022/03/04 21:56:16 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_point(unsigned long long n);
int	ft_print_int(int num);
int	ft_print_unsigned_int(unsigned int num);
int	ft_print_hex(unsigned int hex, char c);

#endif