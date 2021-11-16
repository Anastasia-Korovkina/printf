/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:16:43 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/20 00:18:47 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pros_perc(t_flags *s_flags, int *len)
{
	if (s_flags->minus)
	{
		ft_putchar('%', len);
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
	}
	else if (s_flags->zero)
	{	
		while ((s_flags->width)-- > 1)
			ft_putchar('0', len);
		ft_putchar('%', len);
	}
	else
	{
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
		ft_putchar('%', len);
	}
}
