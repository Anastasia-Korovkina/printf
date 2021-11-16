/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:25:06 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/20 00:31:05 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pros_char(t_flags *s_flags, va_list	*va, int *len)
{
	if (s_flags->minus)
	{
		ft_putchar(va_arg(*va, int), len);
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
	}
	else
	{
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
		ft_putchar(va_arg(*va, int), len);
	}
}
