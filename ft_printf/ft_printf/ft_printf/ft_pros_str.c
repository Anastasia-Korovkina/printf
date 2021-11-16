/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:37:47 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 17:01:08 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pros_str_sub(t_flags *s_flags, char	*copy_arg, int *len, int size)
{
	if (s_flags->minus)
	{
		ft_putstr(copy_arg, len, size);
		while ((s_flags->width)-- > size)
			ft_putchar(' ', len);
	}
	else
	{
		while ((s_flags->width)-- > size)
			ft_putchar(' ', len);
		if (!copy_arg)
			ft_putstr("(null)", len, ft_strlen("(null)"));
		else
			ft_putstr(copy_arg, len, size);
	}
}

void	ft_pros_str(t_flags *s_flags, va_list	*va, int *len)
{
	char	*copy_arg;
	int		size;

	copy_arg = va_arg(*va, char *);
	if (copy_arg == NULL)
		copy_arg = "(null)";
	size = ft_strlen(copy_arg);
	if (s_flags->precision != -1)
	{
		if (s_flags->precision >= 0 && s_flags->precision >= size)
			ft_pros_str_sub(s_flags, copy_arg, len, size);
		else if (s_flags->precision >= 0 && s_flags->precision < size)
		{
			size = s_flags->precision;
			ft_pros_str_sub(s_flags, copy_arg, len, size);
		}
	}
	else
		ft_pros_str_sub(s_flags, copy_arg, len, size);
}
