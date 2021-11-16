/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:41:12 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/14 19:53:41 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag_prec(char **format, t_flags	*s_flags, va_list	*va)
{
	if (**format == '.')
	{
		s_flags->precision = 0;
		(*format)++;
		if (**format == '*')
		{
			s_flags->star2 = 1;
			s_flags->precision = va_arg(*va, int);
			if (s_flags->precision < -1)
				s_flags->precision = -1;
			(*format)++;
		}
		else if (**format >= '0' && **format <= '9')
			s_flags->precision = ft_atoi(format);
	}
}
