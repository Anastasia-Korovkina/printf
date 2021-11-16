/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prosessor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:45:21 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 11:56:03 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prosessor(t_flags *s_flags, va_list	*va, int *len)
{
	if (s_flags->type == '%')
		ft_pros_perc(s_flags, len);
	if (s_flags->type == 'c')
		ft_pros_char(s_flags, va, len);
	if (s_flags->type == 's')
		ft_pros_str(s_flags, va, len);
	if (s_flags->type == 'd' || s_flags->type == 'i')
		ft_pros_int(s_flags, va, len);
	if (s_flags->type == 'u')
		ft_pros_u(s_flags, va, len);
	if (s_flags->type == 'p')
	{
		if (va == NULL)
		{
			ft_putstr("0x0", len, 4);
			return ;
		}
		else
			ft_pros_p(s_flags, va, len);
	}
	if (s_flags->type == 'x' || s_flags->type == 'X')
		ft_pros_x(s_flags, va, len);
}

// cspdiuxX%