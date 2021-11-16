/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_x_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:49:00 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/14 20:07:57 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pros_x_sub5(t_flags *s_flags, int *len, int len_p, char *hash)
{
	if (s_flags->precision == -1)
	{
		ft_putstr(hash, len, 3);
		while ((s_flags->width)-- >= len_p + 2)
			ft_putchar('0', len);
	}
	else if (s_flags->precision < len_p - 1)
	{
		while ((s_flags->width)-- >= len_p + 2)
			ft_putchar(' ', len);
		ft_putstr("0x", len, 3);
	}
	else
	{
		while ((s_flags->width)-- >= s_flags->precision + len_p - 3)
			ft_putchar(' ', len);
		ft_putstr(hash, len, 3);
		while ((s_flags->precision)-- >= len_p)
			ft_putchar('0', len);
	}
}

void	ft_pros_x_sub4(t_flags *s_flags, int *len, int len_p)
{
	char	*hash;

	if (s_flags->hash)
	{
		if (s_flags->type == 'x')
			hash = "0x";
		else
			hash = "0X";
		ft_pros_x_sub5(s_flags, len, len_p, hash);
	}
	else
	{
		if (s_flags->zero)
		{
			if (s_flags->precision < len_p)
			{
				if (s_flags->precision == -1)
					while ((s_flags->width)-- >= len_p)
						ft_putchar('0', len);
				else
					while ((s_flags->width)-- >= len_p)
						ft_putchar(' ', len);
			}
			else
			{
				if (s_flags->precision == -1)
					while ((s_flags->width)-- >= len_p)
						ft_putchar('0', len);
				else if (s_flags->precision > 0)
					while ((s_flags->width)-- > s_flags->precision)
						ft_putchar(' ', len);
				while ((s_flags->precision)-- >= len_p)
					ft_putchar('0', len);
			}
		}
		else
			if (s_flags->precision > 0)
			{
				while ((s_flags->width)-- > s_flags->precision)
					ft_putchar(' ', len);
				while ((s_flags->precision)-- >= len_p)
					ft_putchar('0', len);
			}
			else
				while ((s_flags->width)-- >= len_p)
					ft_putchar(' ', len);
	}
}
