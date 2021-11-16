/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:04:54 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/14 20:12:52 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pros_x_sub3(t_flags *s_flags, int copy_p, int *len, int len_p)
{
	int		fix_precision;
	char	*hex_base;

	fix_precision = s_flags->precision;
	hex_base = ft_check_x(s_flags);
	if (s_flags->precision >= len_p)
	{
		while ((s_flags->precision)-- >= len_p)
			ft_putchar('0', len);
		ft_putx(copy_p, len, hex_base);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else
	{
		ft_putx(copy_p, len, hex_base);
		while ((s_flags->width)-- >= len_p)
			ft_putchar(' ', len);
	}
}

void	ft_pros_x_sub1(t_flags *s_flags, int copy_p, int *len, int len_p)
{
	char	*hex_base;

	hex_base = ft_check_x(s_flags);
	if (s_flags->hash)
	{
		if (s_flags->type == 'x')
			ft_putstr("0x", len, 3);
		else
			ft_putstr("0X", len, 3);
		s_flags->width -= 2;
	}
	if (s_flags->precision >= s_flags->width)
	{
		while ((s_flags->precision)-- >= len_p)
			ft_putchar('0', len);
		ft_putx(copy_p, len, hex_base);
	}
	else
		ft_pros_x_sub3(s_flags, copy_p, len, len_p);
}

void	ft_pros_x_sub2(t_flags *s_flags, int copy_p, int *len, int len_p)
{
	char	*hex_base;

	hex_base = ft_check_x(s_flags);
	if (s_flags->precision >= s_flags->width)
	{
		while ((s_flags->precision)-- >= len_p)
			ft_putchar('0', len);
	}
	else
		ft_pros_x_sub4(s_flags, len, len_p);
	ft_putx(copy_p, len, hex_base);
}

void	ft_pros_x_zero(t_flags *s_flags, int *len)
{
	if (s_flags->precision == 0)
		ft_putstr("", len, ft_strlen(""));
	else if (s_flags->precision > 0)
	{
		if (s_flags->width > s_flags->precision)
			while ((s_flags->width)-- > s_flags->precision)
				ft_putchar(' ', len);
		while ((s_flags->precision)-- > 0)
			ft_putchar('0', len);
	}
	else
	{
		if (s_flags->precision == -1)
			s_flags->width--;
		if (s_flags->minus)
		{
			ft_putchar('0', len);
			if (s_flags->width > 0)
				while ((s_flags->width)-- > 0)
					ft_putchar(' ', len);
		}
		else
		{
			if (s_flags->width > 0)
				while ((s_flags->width)-- > 0)
					ft_putchar(' ', len);
			ft_putchar('0', len);
		}
	}
}

void	ft_pros_x(t_flags *s_flags, va_list	*va, int *len)
{
	unsigned int	copy_p;
	int				len_p;

	copy_p = va_arg(*va, unsigned int);
	len_p = ft_hexlen(copy_p) + 1;
	if (copy_p == 0)
	{
		ft_pros_x_zero(s_flags, len);
		return ;
	}
	if (s_flags->minus)
		ft_pros_x_sub1(s_flags, copy_p, len, len_p);
	else
		ft_pros_x_sub2(s_flags, copy_p, len, len_p);
}
