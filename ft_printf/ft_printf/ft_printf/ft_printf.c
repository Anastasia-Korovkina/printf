/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:17:03 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/14 20:27:41 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(char *format, va_list	*va, int *len)
{
	t_flags	*s_flags;

	s_flags = malloc(sizeof(t_flags));
	while (*format)
	{
		ft_init_flags(s_flags);
		if (*format == '%')
		{
			ft_check_flags_1(&format, s_flags);
			ft_check_flag_width(&format, s_flags, va);
			ft_check_flag_prec(&format, s_flags, va);
			ft_check_flag_type(&format, s_flags);
			ft_prosessor(s_flags, va, len);
		}
		else
			ft_putchar(*(format), len);
		format++;
	}
	free(s_flags);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		len;

	len = 0;
	va_start(va, format);
	ft_parse((char *)format, &va, &len);
	va_end(va);
	return (len);
}

// #include <stdio.h>
// int main ()
// {
// 	int		a = 8;
// 	int		b = -1;
// 	char	c = 'a';
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200;
// 	int		i = 8;
// 	int		j = -12;
// 	int		k = 123456789;
// 	int		l = 0;
// 	int		m = -12345678;
// 	char	*n = "abcdefghijklmnop";
// 	char	*o = "-a";
// 	char	*p = "-12";
// 	char	*q = "0";
// 	char	*r = "%%";
// 	char	*s = "-2147483648";
// 	char	*t = "0x12345678";
// 	char	*u = "-0";
// 	a = 12;
// 	b = 18;
//  	ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
//  	printf("\n");
//  	printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
// }

// TEST(103, print(" %-5u ", -15));
// TEST(104, print(" %-6u ", -16));
// TEST(105, print(" %-1u ", -99));
// 8 -1 8