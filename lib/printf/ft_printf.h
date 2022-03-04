/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:24:07 by mclerico          #+#    #+#             */
/*   Updated: 2021/09/27 20:31:29 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX +9223372036854775807
# define LONG_MIN -9223372036854775808
# define UINT_MIN 4294967295
# define ULONG_MAX	18446744073709551615
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_strlen(char *s);
int		ft_printstr(char *str);
int		ft_putchar(char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putnbr(int nbr, int *c);
void	ft_unsigned(unsigned int n, int *c);
int		ft_putstr(char *str);
int		ft_valid(char c);
void	ft_printhex(char *s);
int		dec_char_hex(unsigned long n);
int		ft_address(void *add);
int		ft_hex(int n, char c);
int		ft_atoi(const char *str);
int		num_len(int n);
void	ft_params(char f, va_list arg, int *c);
int		ft_printf(char const *format, ...);
#endif
